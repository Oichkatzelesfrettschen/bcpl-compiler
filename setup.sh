#!/usr/bin/env bash
# This is the "living" environment setup script used by continuous
# integration and by developers.  It logs all output to setup.log and
# keeps running even when individual installation steps fail.
# Downloads are retried with checksum verification when possible.  Any
# network or installation failure is recorded in the log but does not
# abort the script.
set -euo pipefail
set -x
export DEBIAN_FRONTEND=noninteractive
: > setup.log
# log everything for debugging
exec > >(tee -a setup.log) 2>&1

# helper to pin to the repo's exact version if it exists and fall back to
# alternative package managers on failure. Any failures are logged to
# setup.log but the script continues.
apt_pin_install(){
  pkg="$1"
  ver=$(apt-cache show "$pkg" 2>/dev/null \
        | awk '/^Version:/{print $2; exit}')
  if [ -n "$ver" ]; then
    apt-get install -y "${pkg}=${ver}" || true
  else
    apt-get install -y "$pkg" || true
  fi
  if ! dpkg -s "$pkg" >/dev/null 2>&1; then
    echo "apt-get failed for $pkg" >> setup.log
    if ! pip3 install --break-system-packages "$pkg" >/dev/null 2>&1; then
      echo "pip install failed for $pkg" >> setup.log
      if ! npm install -g "$pkg" >/dev/null 2>&1; then
        echo "npm install failed for $pkg" >> setup.log
        if [ "$pkg" = "capnproto" ] && ! command -v capnp >/dev/null 2>&1; then
          echo "attempting manual install for capnproto" >> setup.log
          CAPNP_URL=https://capnproto.org/capnproto-c++-0.10.4.tar.gz
          if download_with_retry "$CAPNP_URL" /tmp/capnproto.tar.gz "$CAPNP_URL.sha256" && \
             tar -xzf /tmp/capnproto.tar.gz -C /tmp && \
             cd /tmp/capnproto-c++-* && ./configure && make -j"$(nproc)" && make install; then
            cd - >/dev/null 2>&1
            rm -rf /tmp/capnproto-c++-* /tmp/capnproto.tar.gz
          else
            echo "manual install failed for capnproto" >> setup.log
          fi
        fi
      fi
    fi
  fi

}

# download_with_retry URL DEST [CHECKSUM_URL]
# Repeatedly fetches an archive, optionally verifying its SHA256 checksum.
# Failures are logged and the function returns non-zero after 3 attempts.
download_with_retry(){
  local url="$1" dest="$2" sum_url="${3:-}"
  local attempt=0
  while [ $attempt -lt 3 ]; do
    if curl -fsSL "$url" -o "$dest"; then
      if [ -n "$sum_url" ] && curl -fsSL "$sum_url" -o "$dest.sha256"; then
        if sha256sum -c "$dest.sha256" >/dev/null 2>&1; then
          rm -f "$dest.sha256"
          return 0
        else
          echo "checksum mismatch for $dest" >> setup.log
        fi
      else
        [ -n "$sum_url" ] && echo "failed to fetch checksum for $dest" >> setup.log
        return 0
      fi
    else
      echo "download failed for $url" >> setup.log
    fi
    attempt=$((attempt+1))
    sleep 2
  done
  echo "giving up on $url" >> setup.log
  return 1
}

# enable foreign architectures for cross-compilation
for arch in i386 armel armhf arm64 riscv64 powerpc ppc64el ia64; do
  dpkg --add-architecture "$arch"
done

apt-get update -y
apt-get dist-upgrade -y

# core build tools, formatters, analysis, science libs
for pkg in \
  build-essential gcc g++ clang lld llvm libclang-dev llvm-dev \
  clang-format uncrustify astyle editorconfig pre-commit \
  flake8 python3-pytest \
  make bmake ninja-build cmake meson \
  autoconf automake libtool m4 gawk flex bison byacc \
  pkg-config file ca-certificates curl git unzip \
  libopenblas-dev liblapack-dev libeigen3-dev \
  strace ltrace linux-perf systemtap systemtap-sdt-dev crash \
  valgrind kcachegrind trace-cmd kernelshark \
  libasan6 libubsan1 likwid hwloc capnproto; do
  apt_pin_install "$pkg"
done

# Python & deep-learning / MLOps
for pkg in \
  python3 python3-pip python3-dev python3-venv python3-wheel \
  python3-numpy python3-scipy python3-pandas \
  python3-matplotlib python3-scikit-learn \
  python3-torch python3-torchvision python3-torchaudio \
  python3-onnx python3-onnxruntime; do
  apt_pin_install "$pkg"
done

pip3 install --no-cache-dir \
  tensorflow-cpu jax jaxlib \
  tensorflow-model-optimization mlflow onnxruntime-tools \
  atheris \
  black ruff pylint mypy pytest pytest-cov hypothesis

# QEMU emulation for foreign binaries
for pkg in \
  qemu-user-static \
  qemu-system-x86 qemu-system-arm qemu-system-aarch64 \
  qemu-system-riscv64 qemu-system-ppc qemu-system-ppc64 qemu-utils; do
  apt_pin_install "$pkg"
done

# multi-arch cross-compilers
for pkg in \
  bcc bin86 elks-libc \
  gcc-ia64-linux-gnu g++-ia64-linux-gnu \
  gcc-i686-linux-gnu g++-i686-linux-gnu \
  gcc-aarch64-linux-gnu g++-aarch64-linux-gnu \
  gcc-arm-linux-gnueabi g++-arm-linux-gnueabi \
  gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf \
  gcc-riscv64-linux-gnu g++-riscv64-linux-gnu \
  gcc-powerpc-linux-gnu g++-powerpc-linux-gnu \
  gcc-powerpc64-linux-gnu g++-powerpc64-linux-gnu \
  gcc-powerpc64le-linux-gnu g++-powerpc64le-linux-gnu \
  gcc-m68k-linux-gnu g++-m68k-linux-gnu \
  gcc-hppa-linux-gnu g++-hppa-linux-gnu \
  gcc-loongarch64-linux-gnu g++-loongarch64-linux-gnu \
  gcc-mips-linux-gnu g++-mips-linux-gnu \
  gcc-mipsel-linux-gnu g++-mipsel-linux-gnu \
  gcc-mips64-linux-gnuabi64 g++-mips64-linux-gnuabi64 \
  gcc-mips64el-linux-gnuabi64 g++-mips64el-linux-gnuabi64; do
  apt_pin_install "$pkg"
done

# high-level language runtimes and tools
for pkg in \
  golang-go nodejs npm typescript \
  rustc cargo clippy rustfmt \
  lua5.4 liblua5.4-dev luarocks \
  ghc cabal-install hlint stylish-haskell \
  sbcl ecl clisp cl-quicklisp slime cl-asdf \
  ldc gdc dmd-compiler dub libphobos-dev \
  chicken-bin libchicken-dev chicken-doc \
  openjdk-17-jdk maven gradle dotnet-sdk-8 mono-complete \
  swift swift-lldb swiftpm kotlin gradle-plugin-kotlin \
  ruby ruby-dev gem bundler php-cli php-dev composer phpunit \
  r-base r-base-dev dart flutter gnat gprbuild gfortran gnucobol \
  fpc lazarus zig nim nimble crystal shards gforth; do
  apt_pin_install "$pkg"
done

npm install -g eslint

# GUI & desktop-dev frameworks
for pkg in \
  libqt5-dev qtcreator libqt6-dev \
  libgtk1.2-dev libgtk2.0-dev libgtk-3-dev libgtk-4-dev \
  libfltk1.3-dev xorg-dev libx11-dev libxext-dev \
  libmotif-dev openmotif cde \
  xfce4-dev-tools libxfce4ui-2-dev lxde-core lxqt-dev-tools \
  libefl-dev libeina-dev \
  libwxgtk3.0-dev libwxgtk3.0-gtk3-dev \
  libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev \
  libglfw3-dev libglew-dev; do
  apt_pin_install "$pkg"
done

# containers, virtualization, HPC, debug
for pkg in \
  docker.io podman buildah virt-manager libvirt-daemon-system qemu-kvm \
  gdb lldb perf gcovr lcov bcc-tools bpftrace afl++ \
  openmpi-bin libopenmpi-dev mpich; do
  apt_pin_install "$pkg"
done

# IA-16 (8086/286) cross-compiler
IA16_VER=$(curl -fsSL https://api.github.com/repos/tkchia/gcc-ia16/releases/latest 2>>setup.log \
           | awk -F\" '/tag_name/{print $4; exit}') || IA16_VER=""
if [ -n "$IA16_VER" ] && \
   download_with_retry "https://github.com/tkchia/gcc-ia16/releases/download/${IA16_VER}/ia16-elf-gcc-linux64.tar.xz" /tmp/ia16.tar.xz "https://github.com/tkchia/gcc-ia16/releases/download/${IA16_VER}/ia16-elf-gcc-linux64.tar.xz.sha256"; then
  tar -Jxf /tmp/ia16.tar.xz -C /opt && rm /tmp/ia16.tar.xz
  echo 'export PATH=/opt/ia16-elf-gcc/bin:$PATH' > /etc/profile.d/ia16.sh
  export PATH=/opt/ia16-elf-gcc/bin:$PATH
else
  echo "IA16 toolchain download failed" >> setup.log
fi

# protoc installer (pinned)
PROTO_VERSION=25.1
PROTO_URL="https://raw.githubusercontent.com/protocolbuffers/protobuf/v${PROTO_VERSION}/protoc-${PROTO_VERSION}-linux-x86_64.zip"
if download_with_retry "$PROTO_URL" /tmp/protoc.zip "$PROTO_URL.sha256"; then
  unzip -d /usr/local /tmp/protoc.zip && rm /tmp/protoc.zip
else
  echo "protoc download failed" >> setup.log
fi

# gmake alias
command -v gmake >/dev/null 2>&1 || ln -s "$(command -v make)" /usr/local/bin/gmake

# clean up
apt-get clean
rm -rf /var/lib/apt/lists/*

exit 0
