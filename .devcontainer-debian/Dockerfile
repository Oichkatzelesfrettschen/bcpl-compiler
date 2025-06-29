# =============================================================================
# BCPL Compiler Development Container - Debian Sid (Unstable)
# =============================================================================

FROM debian:sid

ARG VARIANT=debian-sid
ARG DEBIAN_FRONTEND=noninteractive

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC
ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8
ENV CMAKE_GENERATOR=Ninja
ENV CC=gcc
ENV CXX=g++

# Create vscode user with sudo privileges
RUN groupadd --gid 1000 vscode \
    && useradd --uid 1000 --gid vscode --shell /bin/bash --create-home vscode \
    && apt-get update \
    && apt-get install -y sudo \
    && echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers.d/vscode \
    && chmod 0440 /etc/sudoers.d/vscode

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
    # Cross-compilation toolchains (Debian Sid has the latest)
    gcc-aarch64-linux-gnu \
    g++-aarch64-linux-gnu \
    gcc-arm-linux-gnueabihf \
    g++-arm-linux-gnueabihf \
    gcc-riscv64-linux-gnu \
    g++-riscv64-linux-gnu \
    gcc-powerpc64le-linux-gnu \
    g++-powerpc64le-linux-gnu \
    gcc-s390x-linux-gnu \
    g++-s390x-linux-gnu \
    gcc-mips64el-linux-gnuabi64 \
    g++-mips64el-linux-gnuabi64

# =============================================================================
# CUTTING-EDGE COMPILERS AND TOOLS
# =============================================================================
RUN apt-get install -y \
    # Latest GCC (Debian Sid typically has the newest)
    gcc-14 \
    g++-14 \
    # Latest Clang/LLVM
    clang \
    clang++ \
    clang-format \
    clang-tidy \
    clang-tools \
    llvm \
    llvm-dev \
    lld \
    # Rust toolchain (latest stable)
    rustc \
    cargo \
    # Go compiler
    golang-go \
    # Alternative compilers
    tinycc \
    # Intel compilers (if available)
    intel-mkl-dev || true

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
    # Advanced analysis tools
    cppcheck \
    splint \
    scan-build \
    iwyu \
    # Profiling tools
    google-perftools \
    libgoogle-perftools-dev \
    # Sanitizers (part of GCC/Clang)
    libc6-dbg

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
    texlive-fonts-recommended \
    # Testing frameworks
    check \
    libcheck-dev \
    unity-dev \
    cmocka-dev \
    criterion-dev \
    # Benchmarking
    libbenchmark-dev \
    libgtest-dev \
    libgmock-dev

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
    netcat-openbsd \
    socat \
    # Modern file tools
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
    usbutils \
    # Modern alternatives
    zoxide \
    direnv

# =============================================================================
# DEVELOPMENT LIBRARIES (Latest versions)
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
    libisl-dev \
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
    libyaml-dev \
    # Regular expressions
    libpcre2-dev \
    # Unicode
    libicu-dev \
    # Scientific computing
    libblas-dev \
    liblapack-dev \
    libfftw3-dev

# =============================================================================
# PYTHON DEVELOPMENT ENVIRONMENT (Latest Python)
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
    python3-requests \
    python3-scipy \
    python3-sympy \
    # Multiple Python versions for testing
    python3.11 \
    python3.12 \
    python3.13 || true

# Install cutting-edge Python packages
RUN python3 -m pip install --no-cache-dir \
    black \
    isort \
    ruff \
    mypy \
    pylint \
    pytest \
    pytest-cov \
    pytest-xdist \
    pytest-benchmark \
    conan \
    meson \
    # Scientific packages
    jupyter \
    ipython \
    notebook \
    matplotlib \
    seaborn \
    plotly \
    # Development tools
    pre-commit \
    commitizen

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
    # Memory debugging
    electric-fence \
    # Fuzzing tools
    afl++ || afl \
    # Code coverage
    lcov \
    gcovr

# =============================================================================
# MODERN PACKAGE MANAGERS AND BUILD SYSTEMS
# =============================================================================

# Install vcpkg
RUN git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg && \
    cd /opt/vcpkg && \
    ./bootstrap-vcpkg.sh && \
    ln -sf /opt/vcpkg/vcpkg /usr/local/bin/vcpkg

# Install latest Bazel
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > /usr/share/keyrings/bazel-archive-keyring.gpg && \
    echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list && \
    apt-get update && apt-get install -y bazel || echo "Bazel installation failed, continuing..."

# Install Buck2 (Meta's build system)
RUN curl -L https://github.com/facebook/buck2/releases/latest/download/buck2-x86_64-unknown-linux-musl.zst | zstd -d > /usr/local/bin/buck2 && \
    chmod +x /usr/local/bin/buck2 || echo "Buck2 installation failed, continuing..."

# =============================================================================
# EXPERIMENTAL AND CUTTING-EDGE TOOLS
# =============================================================================

# Install experimental compilers if available
RUN apt-get install -y \
    # Zig (modern systems programming)
    zig || echo "Zig not available" \
    # Nim compiler
    nim || echo "Nim not available" \
    # Crystal compiler
    crystal || echo "Crystal not available" \
    # D compiler
    gdc || echo "D compiler not available"

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

# Configure shell with Debian Sid specific settings
RUN echo 'export PATH="/opt/vcpkg:$PATH"' >> ~/.bashrc && \
    echo 'export VCPKG_ROOT="/opt/vcpkg"' >> ~/.bashrc && \
    echo 'export CMAKE_TOOLCHAIN_FILE="/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"' >> ~/.bashrc && \
    echo 'export MAKEFLAGS="-j$(nproc)"' >> ~/.bashrc && \
    echo 'export PS1="\[\033[01;32m\]\u@sid-dev\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ "' >> ~/.bashrc && \
    echo 'export DEBIAN_SID=1' >> ~/.bashrc

# Configure git (will be overridden by user)
RUN git config --global init.defaultBranch main && \
    git config --global pull.rebase false && \
    git config --global core.autocrlf input

# Default command
CMD ["/bin/bash"]
