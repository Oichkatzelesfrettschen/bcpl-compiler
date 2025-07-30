#!/usr/bin/env bash
# -----------------------------------------------------------------------------
# Unified build helper for the BCPL compiler.
# Mirrors the configuration options described in docs/BUILD.md.
#
# Usage: ./build.sh [BUILD_TYPE] [ARCHITECTURE]
#   BUILD_TYPE   : Release | Debug | RelWithDebInfo | MinSizeRel
#   ARCHITECTURE : native | x86_64 | arm64 | x86_32 | arm32 | x86_16
#
# Defaults are BUILD_TYPE=Release and ARCHITECTURE=native.  Build
# artifacts are placed under build/<BUILD_TYPE>.
# -----------------------------------------------------------------------------
set -euo pipefail

show_help() {
    cat <<EOF
Usage: $0 [BUILD_TYPE] [ARCHITECTURE]

Build type options:    Release | Debug | RelWithDebInfo | MinSizeRel
Architecture options:  native | x86_64 | arm64 | x86_32 | arm32 | x86_16

Examples:
  $0                # Release build for host architecture
  $0 Debug arm64    # Debug build targeting arm64
EOF
}

if [[ "${1:-}" =~ ^(-h|--help)$ ]]; then
    show_help
    exit 0
fi

BUILD_TYPE="${1:-Release}"
TARGET_ARCH="${2:-native}"
# Map 'native' to the CMake 'auto' setting
[[ "$TARGET_ARCH" == "native" ]] && TARGET_ARCH="auto"
BUILD_DIR="build/${BUILD_TYPE}"

cmake -B "$BUILD_DIR" \
      -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
      -DBCPL_TARGET_ARCH="${TARGET_ARCH}" \
      .

cmake --build "$BUILD_DIR" --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 1)"
