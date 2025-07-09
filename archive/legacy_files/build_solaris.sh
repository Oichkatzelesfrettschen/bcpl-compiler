#!/usr/bin/bash
# build_solaris.sh - Build script for Solaris and illumos systems
# This script builds the BCPL compiler on Solaris/illumos with proper toolchain detection

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Build for Solaris/illumos ===${NC}"

# Detect system type
if [ -f /etc/release ]; then
    if grep -q "Oracle Solaris" /etc/release; then
        SYSTEM_TYPE="solaris"
        echo "Detected: Oracle Solaris"
    elif grep -q "OpenIndiana\|illumos" /etc/release; then
        SYSTEM_TYPE="illumos"
        echo "Detected: illumos/OpenIndiana"
    else
        SYSTEM_TYPE="unknown"
        echo "Unknown Solaris variant"
    fi
else
    echo "Warning: Could not detect system type"
    SYSTEM_TYPE="generic"
fi

# Check for required tools
echo -e "${YELLOW}Checking for required tools...${NC}"

# Check for compiler
if command -v gcc >/dev/null 2>&1; then
    CC=gcc
    echo "Found GCC: $(gcc --version | head -1)"
elif command -v clang >/dev/null 2>&1; then
    CC=clang
    echo "Found Clang: $(clang --version | head -1)"
else
    echo -e "${RED}Error: No suitable C compiler found${NC}"
    echo "Please install GCC or Clang"
    exit 1
fi

# Check for CMake
if ! command -v cmake >/dev/null 2>&1; then
    echo -e "${RED}Error: CMake not found${NC}"
    echo "Please install CMake 3.20 or later"
    echo "On illumos: pkg install cmake"
    echo "On Solaris: pkgutil -i cmake"
    exit 1
fi

# Check for GNU make
if command -v gmake >/dev/null 2>&1; then
    MAKE=gmake
elif command -v make >/dev/null 2>&1 && make --version 2>&1 | grep -q GNU; then
    MAKE=make
else
    echo -e "${RED}Error: GNU make not found${NC}"
    echo "Please install GNU make"
    exit 1
fi

echo "Using make: $MAKE"

# Check for assembler
if command -v as >/dev/null 2>&1; then
    AS=as
    echo "Found assembler: $AS"
else
    echo -e "${RED}Error: Assembler not found${NC}"
    exit 1
fi

# Set up environment
export CC
export MAKE
export AS

# Platform-specific settings
BUILD_DIR="build_${SYSTEM_TYPE}"
CMAKE_FLAGS=(
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_C_COMPILER="$CC"
)

# Solaris-specific settings
if [ "$SYSTEM_TYPE" = "solaris" ]; then
    CMAKE_FLAGS+=(
        -DCMAKE_C_FLAGS="-D_POSIX_C_SOURCE=200809L -D__EXTENSIONS__"
        -DCMAKE_EXE_LINKER_FLAGS="-lsocket -lnsl"
    )
    echo "Applied Oracle Solaris specific settings"
elif [ "$SYSTEM_TYPE" = "illumos" ]; then
    CMAKE_FLAGS+=(
        -DCMAKE_C_FLAGS="-D_POSIX_C_SOURCE=200809L"
        -DCMAKE_EXE_LINKER_FLAGS="-lsocket -lnsl"
    )
    echo "Applied illumos specific settings"
fi

# Architecture detection
ARCH=$(uname -p)
case "$ARCH" in
    i386|x86_64)
        CMAKE_FLAGS+=(-DBITS=64)
        echo "Building for 64-bit x86"
        ;;
    sparc)
        # SPARC systems
        CMAKE_FLAGS+=(-DBITS=64)
        echo "Building for 64-bit SPARC"
        ;;
    *)
        echo "Unknown architecture: $ARCH"
        CMAKE_FLAGS+=(-DBITS=64)
        ;;
esac

# Check for bootstrap files
echo -e "${YELLOW}Checking for bootstrap files...${NC}"
if [ ! -f "src/st.O" ] || [ ! -f "src/blib.O" ]; then
    echo "Bootstrap OCODE files missing, attempting to restore from git..."
    
    if command -v git >/dev/null 2>&1 && [ -d ".git" ]; then
        # Find commit with bootstrap files
        bootstrap_commit=$(git rev-list --all | while read commit; do 
            if git ls-tree -r $commit 2>/dev/null | grep -q "st\.O"; then 
                echo $commit
                break
            fi
        done)
        
        if [ -n "$bootstrap_commit" ]; then
            echo "Restoring bootstrap files from commit: $bootstrap_commit"
            git show $bootstrap_commit:src/st.O > src/st.O
            git show $bootstrap_commit:src/blib.O > src/blib.O
            echo "Bootstrap files restored"
        else
            echo -e "${RED}Error: Could not find bootstrap files in git history${NC}"
            exit 1
        fi
    else
        echo -e "${RED}Error: Bootstrap files missing and git not available${NC}"
        exit 1
    fi
fi

# Clean and create build directory
echo -e "${YELLOW}Setting up build directory...${NC}"
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Configure build
echo -e "${YELLOW}Configuring build...${NC}"
cmake -B "$BUILD_DIR" "${CMAKE_FLAGS[@]}" .

# Build
echo -e "${YELLOW}Building BCPL compiler...${NC}"
cmake --build "$BUILD_DIR" --parallel $(nproc 2>/dev/null || echo 2)

# Test
echo -e "${YELLOW}Testing build...${NC}"
if [ -f "$BUILD_DIR/src/cg" ] && [ -f "$BUILD_DIR/src/op" ]; then
    echo -e "${GREEN}Core binaries built successfully${NC}"
    
    # Test basic functionality
    if echo "// Test" | "$BUILD_DIR/src/cg" >/dev/null 2>&1; then
        echo -e "${GREEN}Code generator test passed${NC}"
    else
        echo -e "${YELLOW}Warning: Code generator test failed${NC}"
    fi
    
    echo
    echo "Build completed successfully!"
    echo "Binaries located in: $BUILD_DIR/src/"
    echo "  - cg (code generator)"
    echo "  - op (optimizer)"
    
    if [ -f "$BUILD_DIR/src/llcg" ]; then
        echo "  - llcg (LLVM backend)"
    fi
    
    echo
    echo "To install:"
    echo "  $MAKE -C $BUILD_DIR install"
    
else
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi

echo
echo -e "${GREEN}Build complete for $SYSTEM_TYPE${NC}"
