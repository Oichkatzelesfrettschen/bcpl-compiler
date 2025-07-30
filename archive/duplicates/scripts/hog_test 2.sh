#!/bin/sh -e
# Run heavy tests with clang and sanitizers
BITS=${BITS:-64}
CROSS_PREFIX=${CROSS_PREFIX:-}
make -C src clean
make -C src CC=clang CFLAGS="-std=c23 -fsanitize=address,undefined -g" BITS=$BITS CROSS_PREFIX=$CROSS_PREFIX all
make -C tools BC=../src/bcplc test
