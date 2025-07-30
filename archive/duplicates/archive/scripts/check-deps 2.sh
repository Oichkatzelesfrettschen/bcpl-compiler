#!/bin/sh -e

# Check required build tools before running makeall.sh
# Verifies clang, as, ld and the cross toolchain specified by
# CROSS_PREFIX and BITS.

BITS=${BITS:-64}
CROSS_PREFIX=${CROSS_PREFIX:-}

missing=0
check_tool() {
    if ! command -v "$1" >/dev/null 2>&1; then
        echo "Missing required tool: $1" >&2
        missing=1
    fi
}

# Base toolchain
check_tool clang
check_tool as
check_tool ld

# Cross toolchain if requested
if [ -n "$CROSS_PREFIX" ]; then
    check_tool "${CROSS_PREFIX}clang"
    check_tool "${CROSS_PREFIX}as"
    check_tool "${CROSS_PREFIX}ld"
fi

if [ "$missing" -ne 0 ]; then
    echo "One or more required tools are missing." >&2
    exit 1
fi

exit 0
