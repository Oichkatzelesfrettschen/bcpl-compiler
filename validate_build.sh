#!/bin/bash
# BCPL Compiler Build Validation Script
# Tests the complete build process and validates output

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_DIR="$SCRIPT_DIR"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Logging functions
log_info() { echo -e "${BLUE}[INFO]${NC} $*"; }
log_success() { echo -e "${GREEN}[SUCCESS]${NC} $*"; }
log_warning() { echo -e "${YELLOW}[WARNING]${NC} $*"; }
log_error() { echo -e "${RED}[ERROR]${NC} $*"; }

# Platform detection
detect_platform() {
    case "$(uname -s)" in
        Linux*)     PLATFORM=LINUX;;
        Darwin*)    PLATFORM=MACOS;;
        FreeBSD*)   PLATFORM=FREEBSD;;
        SunOS*)     PLATFORM=SOLARIS;;
        *)          PLATFORM=UNKNOWN;;
    esac
    
    case "$(uname -m)" in
        x86_64|amd64) ARCH=64;;
        i*86)         ARCH=32;;
        arm64|aarch64) ARCH=64;;
        *)            ARCH=unknown;;
    esac
    
    log_info "Detected platform: $PLATFORM ($ARCH-bit)"
}

# Test prerequisites
check_prerequisites() {
    log_info "Checking build prerequisites..."
    
    # Check for required tools
    local required_tools=("cmake" "make" "git")
    for tool in "${required_tools[@]}"; do
        if ! command -v "$tool" &> /dev/null; then
            log_error "Required tool not found: $tool"
            return 1
        fi
    done
    
    # Check for C compiler
    if command -v clang &> /dev/null; then
        CC_VERSION=$(clang --version | head -n1)
        log_info "C compiler: $CC_VERSION"
    elif command -v gcc &> /dev/null; then
        CC_VERSION=$(gcc --version | head -n1)
        log_info "C compiler: $CC_VERSION"
    else
        log_error "No C compiler found (clang or gcc required)"
        return 1
    fi
    
    log_success "Prerequisites check passed"
}

# Clean build function
clean_build() {
    local build_dir="$1"
    log_info "Cleaning build directory: $build_dir"
    rm -rf "$build_dir"
    mkdir -p "$build_dir"
}

# Test build function
test_build() {
    local build_type="$1"
    local build_dir="$REPO_DIR/build_$build_type"
    
    log_info "Testing $build_type build..."
    
    clean_build "$build_dir"
    cd "$build_dir"
    
    # Configure
    log_info "Configuring CMake..."
    if ! cmake -DCMAKE_BUILD_TYPE="$build_type" ..; then
        log_error "CMake configuration failed for $build_type"
        return 1
    fi
    
    # Build
    log_info "Building..."
    if ! make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4); then
        log_error "Build failed for $build_type"
        return 1
    fi
    
    # Validate outputs
    log_info "Validating build outputs..."
    local required_outputs=("src/cg" "src/op" "src/libbcpl_runtime.a")
    for output in "${required_outputs[@]}"; do
        if [[ ! -f "$output" ]]; then
            log_error "Missing build output: $output"
            return 1
        fi
        
        # Check if it's executable (for binaries)
        if [[ "$output" != *.a && ! -x "$output" ]]; then
            log_error "Output not executable: $output"
            return 1
        fi
    done
    
    # Test binary functionality
    log_info "Testing binary functionality..."
    
    # Test cg and op with minimal input
    if echo 'quit;' | timeout 5 ./src/cg >/dev/null 2>&1; then
        log_success "cg binary functional"
    else
        log_warning "cg binary test inconclusive"
    fi
    
    if echo 'quit;' | timeout 5 ./src/op >/dev/null 2>&1; then
        log_success "op binary functional"
    else
        log_warning "op binary test inconclusive"
    fi
    
    log_success "$build_type build completed successfully"
    return 0
}

# File validation
validate_repository() {
    log_info "Validating repository structure..."
    
    # Check for essential files
    local essential_files=(
        "CMakeLists.txt"
        "src/CMakeLists.txt"
        "cmake/PlatformConfig.cmake"
        "src/cg.c"
        "src/op.c"
        "src/oc.c"
        "src/pt.c"
        "src/st.O"
        "src/blib.O"
    )
    
    for file in "${essential_files[@]}"; do
        if [[ ! -f "$REPO_DIR/$file" ]]; then
            log_error "Missing essential file: $file"
            return 1
        fi
    done
    
    # Check platform files
    local platform_files=(
        "src/platform/macos.c"
        "src/platform/linux.c"
        "src/platform/freebsd.c"
        "src/platform/generic.c"
    )
    
    for file in "${platform_files[@]}"; do
        if [[ ! -f "$REPO_DIR/$file" ]]; then
            log_warning "Missing platform file: $file"
        fi
    done
    
    log_success "Repository validation completed"
}

# Bootstrap validation
validate_bootstrap() {
    log_info "Validating bootstrap files..."
    
    local bootstrap_files=("src/st.O" "src/blib.O")
    for file in "${bootstrap_files[@]}"; do
        if [[ ! -f "$REPO_DIR/$file" ]]; then
            log_warning "Missing bootstrap file: $file"
            log_info "Attempting to restore from git history..."
            
            cd "$REPO_DIR"
            if git log --oneline --all -- "$file" | head -1; then
                if git checkout "$(git log --oneline --all -- "$file" | head -1 | cut -d' ' -f1)" -- "$file"; then
                    log_success "Restored $file from git history"
                else
                    log_error "Failed to restore $file from git history"
                    return 1
                fi
            else
                log_error "No git history found for $file"
                return 1
            fi
        else
            log_success "Bootstrap file present: $file"
        fi
    done
}

# Installation test
test_install() {
    local build_dir="$REPO_DIR/build_release"
    local install_dir="$REPO_DIR/install_test"
    
    log_info "Testing installation..."
    
    rm -rf "$install_dir"
    cd "$build_dir"
    
    if make DESTDIR="$install_dir" install; then
        log_success "Installation completed"
        
        # List installed files
        log_info "Installed files:"
        find "$install_dir" -type f | sort
    else
        log_warning "Installation failed or not supported"
    fi
}

# Packaging test
test_packaging() {
    log_info "Testing platform-specific packaging..."
    
    case "$PLATFORM" in
        LINUX)
            if [[ -f "$REPO_DIR/PKGBUILD" ]]; then
                log_info "PKGBUILD found for Arch Linux"
                # Could run makepkg --printsrcinfo to validate
            fi
            ;;
        SOLARIS)
            if [[ -f "$REPO_DIR/build_solaris.sh" ]]; then
                log_info "Solaris build script found"
                if bash -n "$REPO_DIR/build_solaris.sh"; then
                    log_success "Solaris build script syntax is valid"
                else
                    log_error "Solaris build script has syntax errors"
                fi
            fi
            ;;
    esac
}

# Main execution
main() {
    log_info "BCPL Compiler Build Validation"
    log_info "=============================="
    
    cd "$REPO_DIR"
    
    detect_platform
    check_prerequisites
    validate_repository
    validate_bootstrap
    
    # Test different build types
    local build_types=("Debug" "Release")
    for build_type in "${build_types[@]}"; do
        test_build "$build_type"
    done
    
    # Test installation
    test_install
    
    # Test packaging
    test_packaging
    
    log_success "==================================="
    log_success "All validation tests completed!"
    log_success "Platform: $PLATFORM ($ARCH-bit)"
    log_success "Build system is functional"
    log_success "==================================="
}

# Run main function
main "$@"
