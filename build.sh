#!/bin/bash
#!/bin/bash
# build.sh - Unified BCPL compiler build helper
# Usage: ./build.sh [BuildType] [Architecture]
# BuildType    : Release, Debug, RelWithDebInfo, MinSizeRel
# Architecture : native (default), x86_64, arm64, x86_32, arm32, x86_16
# Build artifacts are placed under build/<BuildType>-<Architecture>

set -euo pipefail

BUILD_TYPE="${1:-Release}"
ARCHITECTURE="${2:-native}"

# Validate architecture argument
SUPPORTED_ARCHS=(native x86_64 arm64 x86_32 arm32 x86_16)
if [[ ! " ${SUPPORTED_ARCHS[*]} " =~ " ${ARCHITECTURE} " ]]; then
    echo "Error: unsupported architecture '${ARCHITECTURE}'." >&2
    echo "Supported architectures: ${SUPPORTED_ARCHS[*]}" >&2
    exit 1
fi

# Resolve 'native' architecture to host
if [[ "${ARCHITECTURE}" == "native" ]]; then
    case "$(uname -m)" in
        x86_64|amd64) ARCHITECTURE="x86_64" ;;
        aarch64|arm64) ARCHITECTURE="arm64" ;;
        i?86) ARCHITECTURE="x86_32" ;;
        arm*) ARCHITECTURE="arm32" ;;
    esac
fi

BUILD_DIR="build/${BUILD_TYPE}-${ARCHITECTURE}"

cmake -B "$BUILD_DIR" \
      -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
      -DBCPL_TARGET_ARCH="${ARCHITECTURE}" \
      .

# Build using all available cores
cmake --build "$BUILD_DIR" --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)"

