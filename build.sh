#!/bin/bash
# build.sh - Wrapper script for invoking CMake builds
# Usage: ./build.sh [BuildType]
# Defaults to "Release" when no argument is provided.
# The build artifacts are placed under build/<BuildType>.
set -e
BUILD_TYPE="${1:-Release}"
BUILD_DIR="build/${BUILD_TYPE}"

# Configure with the chosen build type
cmake -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" .

# Build using all available cores
cmake --build "$BUILD_DIR" --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
