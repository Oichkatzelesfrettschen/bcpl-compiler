# BCPL Compiler Development Container
FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    ninja-build \
    autotools-dev \
    autoconf \
    automake \
    libtool \
    pkg-config \
    gdb \
    valgrind \
    strace \
    ltrace \
    binutils \
    elfutils \
    file \
    xxd \
    hexdump \
    doxygen \
    graphviz \
    cppcheck \
    clang-format \
    clang-tidy \
    git \
    curl \
    wget \
    tree \
    htop \
    tmux \
    vim \
    nano \
    less \
    grep \
    sed \
    awk \
    unzip \
    tar \
    rsync \
    gcc-multilib \
    g++-multilib \
    libc6-dev-i386 \
    && rm -rf /var/lib/apt/lists/*

# Set up the working directory
WORKDIR /workspace

# Switch to the vscode user
USER vscode

# Set up shell configuration
RUN echo 'export PS1="\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ "' >> ~/.bashrc

# Default command
CMD ["/bin/bash"]
