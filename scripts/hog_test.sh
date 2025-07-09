#!/bin/sh -e
# Run heavy tests with clang and sanitizers
BITS=${BITS:-64}
CROSS_PREFIX=${CROSS_PREFIX:-}
make -C src clean
# Build with clang and enable sanitizers.  We let the Makefile append the
# standard warning flags and the BITS-dependent configuration options.
make -C src CC=clang CFLAGS_EXTRA="-fsanitize=address,undefined" \
    BITS=$BITS CROSS_PREFIX=$CROSS_PREFIX all
make -C tools BC=../src/bcplc test
