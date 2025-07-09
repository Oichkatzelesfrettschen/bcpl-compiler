#!/bin/sh -e

# Make script for bcplc

DIRS="src docs"
MAKE=make

# Verify required tools before proceeding
script_dir="$(cd "$(dirname "$0")" && pwd)"
"$script_dir/check-deps.sh"

# Initialize
if test $# -gt 1; then
    echo "usage: makeall [target]" 1>&2
    exit 2
fi
target=$1
if test -z "$1"; then
    target="all"
fi

# Remove old sys.s symlink if it exists, as src/Makefile now handles SYS_SRC directly
if [ -L src/sys.s ]; then
    echo "Removing old src/sys.s symlink."
    rm -f src/sys.s
elif [ -e src/sys.s ]; then
    echo "Warning: src/sys.s exists and is not a symlink. Please check."
fi

# Make
for dir in ${DIRS}
do
    echo "===== ${dir} ====="
    (cd ${dir} && ${MAKE} ${target})
done

if [ "$target" = "all" ] && [ -z "$SKIP_TESTS" ]; then
    echo "===== tool tests ====="
    if command -v bcplc >/dev/null 2>&1; then
        BC=bcplc
    else
        BC=../src/bcplc
    fi
    (cd tools && ${MAKE} BC=${BC} test)
fi
