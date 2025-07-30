# =============================================================================
# BCPL Compiler Development Container - Ubuntu 24.04
# =============================================================================

FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

ARG VARIANT=ubuntu-24.04
ARG DEBIAN_FRONTEND=noninteractive

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC
ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8
ENV CMAKE_GENERATOR=Ninja
ENV CC=gcc
ENV CXX=g++

# Update package lists and install essential packages
RUN apt-get update && apt-get upgrade -y

# =============================================================================
# CORE BUILD TOOLS
# =============================================================================
RUN apt-get install -y \
    # Essential build tools
    build-essential \
    gcc \
    g++ \
    gcc-multilib \
    g++-multilib \
    libc6-dev \
    libc6-dev-i386 \
    linux-libc-dev \
    make \
    cmake \
    ninja-build \
    meson \
    autotools-dev \
    autoconf \
    automake \
    libtool \
    libtool-bin \
    pkg-config \
    m4 \
    flex \
    bison \
    gperf \
    texinfo \
    # Cross-compilation toolchains
    gcc-aarch64-linux-gnu \
    g++-aarch64-linux-gnu \
    gcc-arm-linux-gnueabihf \
    g++-arm-linux-gnueabihf \
    gcc-riscv64-linux-gnu \
    g++-riscv64-linux-gnu

# =============================================================================
# DEBUGGING AND ANALYSIS TOOLS
# =============================================================================
RUN apt-get install -y \
    # Debuggers
    gdb \
    gdb-multiarch \
    lldb \
    # Performance analysis
    valgrind \
    strace \
    ltrace \
    perf-tools-unstable \
    # Binary analysis
    binutils \
    binutils-multiarch \
    elfutils \
    objdump \
    readelf \
    nm \
    file \
    xxd \
    hexdump \
    hexedit \
    # Code analysis
    cppcheck \
    clang \
    clang-format \
    clang-tidy \
    clang-tools \
    splint \
    # Static analysis
    scan-build \
    iwyu

# =============================================================================
# DOCUMENTATION AND TESTING
# =============================================================================
RUN apt-get install -y \
    # Documentation
    doxygen \
    graphviz \
    pandoc \
    texlive-latex-base \
    texlive-latex-extra \
    # Testing frameworks
    check \
    libcheck-dev \
    unity-dev \
    cmocka-dev \
    criterion-dev

# =============================================================================
# SYSTEM UTILITIES
# =============================================================================
RUN apt-get install -y \
    # Version control
    git \
    git-lfs \
    subversion \
    mercurial \
    # Network tools
    curl \
    wget \
    netcat \
    socat \
    # File operations
    tree \
    fd-find \
    ripgrep \
    fzf \
    bat \
    exa \
    # Process monitoring
    htop \
    iotop \
    iftop \
    # Terminal utilities
    tmux \
    screen \
    vim \
    neovim \
    nano \
    emacs-nox \
    # Text processing
    less \
    grep \
    sed \
    awk \
    jq \
    yq \
    # Compression
    unzip \
    zip \
    tar \
    gzip \
    bzip2 \
    xz-utils \
    zstd \
    # File synchronization
    rsync \
    # System information
    lshw \
    dmidecode \
    pciutils \
    usbutils

# =============================================================================
# DEVELOPMENT LIBRARIES
# =============================================================================
RUN apt-get install -y \
    # Standard libraries
    libc6-dev \
    libstdc++-dev \
    # Math libraries
    libm6 \
    libgmp-dev \
    libmpfr-dev \
    libmpc-dev \
    # Threading
    libpthread-stubs0-dev \
    # Networking
    libcurl4-openssl-dev \
    libssl-dev \
    # Compression
    zlib1g-dev \
    libbz2-dev \
    liblzma-dev \
    libzstd-dev \
    # Database
    libsqlite3-dev \
    # XML/JSON
    libxml2-dev \
    libjansson-dev \
    # Regular expressions
    libpcre2-dev \
    # Unicode
    libicu-dev

# =============================================================================
# PYTHON DEVELOPMENT ENVIRONMENT
# =============================================================================
RUN apt-get install -y \
    python3 \
    python3-dev \
    python3-pip \
    python3-venv \
    python3-setuptools \
    python3-wheel \
    python3-distutils \
    python3-pytest \
    python3-numpy \
    python3-matplotlib \
    python3-pandas \
    python3-requests

# Install additional Python packages
RUN python3 -m pip install --no-cache-dir \
    black \
    isort \
    flake8 \
    mypy \
    pylint \
    pytest-cov \
    pytest-xdist \
    conan \
    vcpkg

# =============================================================================
# SPECIALIZED TOOLS
# =============================================================================
RUN apt-get install -y \
    # Container tools
    docker.io \
    docker-compose \
    podman \
    # Virtual environments
    qemu-user-static \
    # Hardware simulation
    qemu-system \
    # Assembly tools
    nasm \
    yasm \
    gas \
    # Linkers
    ld \
    gold \
    lld \
    # Profiling
    google-perftools \
    libgoogle-perftools-dev \
    # Memory debugging
    electric-fence

# =============================================================================
# MODERN C/C++ PACKAGE MANAGERS
# =============================================================================

# Install vcpkg
RUN git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg && \
    cd /opt/vcpkg && \
    ./bootstrap-vcpkg.sh && \
    ln -sf /opt/vcpkg/vcpkg /usr/local/bin/vcpkg

# Install Conan 2.0
RUN python3 -m pip install --no-cache-dir conan

# =============================================================================
# CLEANUP AND CONFIGURATION
# =============================================================================

# Clean up package cache
RUN apt-get autoremove -y && \
    apt-get autoclean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Set up the working directory
WORKDIR /workspace

# Create useful directories
RUN mkdir -p /workspace/{build,install,docs,tests}

# Set up environment for vscode user
USER vscode

# Configure shell
RUN echo 'export PATH="/opt/vcpkg:$PATH"' >> ~/.bashrc && \
    echo 'export VCPKG_ROOT="/opt/vcpkg"' >> ~/.bashrc && \
    echo 'export CMAKE_TOOLCHAIN_FILE="/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"' >> ~/.bashrc && \
    echo 'export MAKEFLAGS="-j$(nproc)"' >> ~/.bashrc && \
    echo 'export PS1="\[\033[01;32m\]\u@bcpl-dev\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ "' >> ~/.bashrc

# Configure git (will be overridden by user)
RUN git config --global init.defaultBranch main && \
    git config --global pull.rebase false && \
    git config --global core.autocrlf input

# Default command
CMD ["/bin/bash"]
