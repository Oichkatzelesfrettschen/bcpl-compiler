#!/bin/bash
# Multi-Architecture BCPL Compiler Build Script
# Builds for all supported architectures

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(dirname "$SCRIPT_DIR")"

# Configuration
SUPPORTED_ARCHS="arm64 x86_64"
OPTIONAL_ARCHS="arm32 x86_32 x86_16"
BUILD_TYPE="${BUILD_TYPE:-Release}"
ENABLE_CROSS_COMPILE="${ENABLE_CROSS_COMPILE:-OFF}"

echo "=== Multi-Architecture BCPL Compiler Build ==="
echo "Build type: $BUILD_TYPE"
echo "Cross-compilation: $ENABLE_CROSS_COMPILE"
echo "Supported architectures: $SUPPORTED_ARCHS"

# Function to build for a specific architecture
build_arch() {
    local arch="$1"
    local build_dir="build-${arch}"
    
    echo ""
    echo ">>> Building for $arch..."
    
    # Create build directory
    mkdir -p "$build_dir"
    cd "$build_dir"
    
    # Configure CMake
    local cmake_args=(
        -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
        -DTARGET_ARCH="$arch"
        -DENABLE_CROSS_COMPILE="$ENABLE_CROSS_COMPILE"
    )
    
    # Architecture-specific settings
    case "$arch" in
        "arm64")
            if [[ "$OSTYPE" == "darwin"* ]]; then
                cmake_args+=(-DCMAKE_OSX_ARCHITECTURES="arm64")
            fi
            ;;
        "x86_64")
            if [[ "$OSTYPE" == "darwin"* ]]; then
                cmake_args+=(-DCMAKE_OSX_ARCHITECTURES="x86_64")
            fi
            ;;
        "arm32")
            cmake_args+=(-DENABLE_ARM32=ON)
            ;;
        "x86_32")
            cmake_args+=(-DENABLE_X86_32=ON)
            ;;
        "x86_16")
            cmake_args+=(-DENABLE_X86_16=ON)
            ;;
    esac
    
    echo "CMake arguments: ${cmake_args[*]}"
    
    if cmake "${cmake_args[@]}" ..; then
        if make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4); then
            echo "✓ Successfully built for $arch"
            
            # List generated binaries
            echo "Generated binaries:"
            find src -name "*_${arch}" -type f -executable 2>/dev/null | sort | while read -r binary; do
                echo "  - $(basename "$binary")"
            done
        else
            echo "✗ Build failed for $arch"
            return 1
        fi
    else
        echo "✗ Configuration failed for $arch"
        return 1
    fi
    
    cd ..
}

# Function to check if cross-compilation tools are available
check_cross_tools() {
    local arch="$1"
    case "$arch" in
        "arm64")
            if [[ "$OSTYPE" != "darwin"* ]] && [[ "$(uname -m)" != "aarch64" ]]; then
                if ! command -v aarch64-linux-gnu-gcc >/dev/null 2>&1; then
                    echo "Warning: aarch64-linux-gnu-gcc not found for ARM64 cross-compilation"
                    return 1
                fi
            fi
            ;;
        "arm32")
            if ! command -v arm-linux-gnueabihf-gcc >/dev/null 2>&1; then
                echo "Warning: arm-linux-gnueabihf-gcc not found for ARM32 cross-compilation"
                return 1
            fi
            ;;
        "x86_16")
            if ! command -v i8086-linux-gcc >/dev/null 2>&1; then
                echo "Warning: i8086-linux-gcc not found for x86_16 compilation"
                echo "You may need to install ia16-elf-gcc or similar"
                return 1
            fi
            ;;
    esac
    return 0
}

# Main build process
cd "$ROOT_DIR"

echo ""
echo "Checking build environment..."

# Build for primary architectures
for arch in $SUPPORTED_ARCHS; do
    if build_arch "$arch"; then
        echo "✓ $arch build completed"
    else
        echo "✗ $arch build failed"
        exit 1
    fi
done

# Build for optional architectures (if tools available)
if [[ "$ENABLE_CROSS_COMPILE" == "ON" ]]; then
    echo ""
    echo "Building optional architectures..."
    
    for arch in $OPTIONAL_ARCHS; do
        if check_cross_tools "$arch"; then
            if build_arch "$arch"; then
                echo "✓ $arch build completed"
            else
                echo "⚠ $arch build failed (optional)"
            fi
        else
            echo "⚠ Skipping $arch (cross-compilation tools not available)"
        fi
    done
fi

# Create universal binaries on macOS
if [[ "$OSTYPE" == "darwin"* ]] && [[ -d "build-arm64" ]] && [[ -d "build-x86_64" ]]; then
    echo ""
    echo "Creating Universal Binaries..."
    
    mkdir -p "build-universal/src"
    
    for binary in cg op st; do
        if [[ -f "build-arm64/src/${binary}_arm64" ]] && [[ -f "build-x86_64/src/${binary}_x86_64" ]]; then
            echo "Creating universal ${binary}..."
            lipo -create \
                "build-arm64/src/${binary}_arm64" \
                "build-x86_64/src/${binary}_x86_64" \
                -output "build-universal/src/${binary}"
        fi
    done
    
    # Create universal runtime library
    if [[ -f "build-arm64/src/libbcpl_runtime_arm64.a" ]] && [[ -f "build-x86_64/src/libbcpl_runtime_x86_64.a" ]]; then
        echo "Creating universal runtime library..."
        lipo -create \
            "build-arm64/src/libbcpl_runtime_arm64.a" \
            "build-x86_64/src/libbcpl_runtime_x86_64.a" \
            -output "build-universal/src/libbcpl_runtime.a"
    fi
    
    echo "✓ Universal binaries created in build-universal/"
fi

echo ""
echo "=== Build Summary ==="
echo "Successfully built architectures:"
for arch in $SUPPORTED_ARCHS $OPTIONAL_ARCHS; do
    if [[ -d "build-${arch}" ]]; then
        echo "  ✓ $arch"
    fi
done

if [[ -d "build-universal" ]]; then
    echo "  ✓ Universal Binary (macOS)"
fi

echo ""
echo "Build complete! Individual architecture binaries are in build-<arch>/src/"
echo "To test a specific architecture:"
echo "  cd build-<arch> && make test"
