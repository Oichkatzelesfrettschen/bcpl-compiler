#!/usr/bin/env bash
set -euo pipefail

apt-get update -y
apt-get install -y gdb strace valgrind

exit 0
