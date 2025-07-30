#!/bin/bash
# Unified build script for the BCPL compiler
# Usage: ./build.sh [BUILD_TYPE] [ARCH]

set -euo pipefail

BUILD_TYPE=${1:-Release}
ARCH=${2:-native}
if [ "$ARCH" = "native" ]; then ARCH=auto; fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/builds/${BUILD_TYPE}_${ARCH}"

if command -v ninja >/dev/null 2>&1; then
    GEN="Ninja"
else
    GEN="Unix Makefiles"
fi

mkdir -p "${BUILD_DIR}"

cmake -S "${SCRIPT_DIR}" -B "${BUILD_DIR}" \
      -G "${GEN}" \
      -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
      -DBCPL_TARGET_ARCH="${ARCH}"

cmake --build "${BUILD_DIR}" --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu || echo 4)"
