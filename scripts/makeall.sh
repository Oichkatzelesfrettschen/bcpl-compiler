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

# Configure
if test -e src/sys.s; then
    :
else
    os=`uname`
    case "${os}" in
    FreeBSD)
        sys="sys_freebsd.s" ;;
    Linux)
        sys="sys_linux.s" ;;
    *)
        echo "${os}: Not supported" 1>&2
        exit 2
    esac
    ln -s ${sys} src/sys.s
    echo "Configured for ${os}"
fi

# Make
for dir in ${DIRS}
do
    echo "===== ${dir} ====="
    (cd ${dir} && ${MAKE} ${target})
done

if [ "$target" = "all" ]; then
    echo "===== tool tests ====="
    if command -v bcplc >/dev/null 2>&1; then
        BC=bcplc
    else
        BC=../src/bcplc
    fi
    (cd tools && ${MAKE} BC=${BC} test)
fi
