#!/bin/bash

# BCPL Compiler Development Environment Setup Script
# Ubuntu 24.04 Dev Container

set -e

echo "🚀 Setting up BCPL Compiler development environment..."

# Update package lists
echo "📦 Updating package lists..."
sudo apt-get update

# Install essential build tools
echo "🔨 Installing build tools..."
sudo apt-get install -y \
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
    pkg-config

# Install additional development tools
echo "🛠️  Installing development tools..."
sudo apt-get install -y \
    gdb \
    valgrind \
    strace \
    ltrace \
    perf-tools-unstable \
    binutils \
    elfutils \
    file \
    xxd \
    hexdump

# Install documentation and analysis tools
echo "📚 Installing documentation tools..."
sudo apt-get install -y \
    doxygen \
    graphviz \
    cppcheck \
    clang-format \
    clang-tidy

# Install version control and utilities
echo "🔧 Installing utilities..."
sudo apt-get install -y \
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
    rsync

# Install cross-compilation tools (as mentioned in the project)
echo "🌐 Installing cross-compilation tools..."
sudo apt-get install -y \
    gcc-multilib \
    g++-multilib \
    libc6-dev-i386

# Clean up
echo "🧹 Cleaning up..."
sudo apt-get autoremove -y
sudo apt-get autoclean

# Set up Git configuration (if not already set)
echo "🔐 Setting up Git..."
if [ -z "$(git config --global user.name)" ]; then
    echo "Please set your Git username: git config --global user.name 'Your Name'"
fi
if [ -z "$(git config --global user.email)" ]; then
    echo "Please set your Git email: git config --global user.email 'your.email@example.com'"
fi

# Make project scripts executable
echo "🔑 Making scripts executable..."
find /workspace -name "*.sh" -type f -exec chmod +x {} \; 2>/dev/null || true

# Create useful aliases
echo "⚡ Setting up aliases..."
cat >> ~/.bashrc << 'EOF'

# BCPL Compiler Development Aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'
alias ..='cd ..'
alias ...='cd ../..'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'

# Build aliases
alias cmake-build='cmake --build build'
alias cmake-clean='rm -rf build && mkdir build'
alias make-clean='make clean'

# Git aliases
alias gs='git status'
alias ga='git add'
alias gc='git commit'
alias gp='git push'
alias gl='git log --oneline --graph'
alias gb='git branch -a'

# BCPL specific
alias bcpl-test='./test_bcpl.sh'
alias bcpl-build='./build.sh'
alias bcpl-validate='./validate_build.sh'
EOF

# Set up ZSH aliases if ZSH is being used
if [ -f ~/.zshrc ]; then
    cat >> ~/.zshrc << 'EOF'

# BCPL Compiler Development Aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'
alias ..='cd ..'
alias ...='cd ../..'
alias grep='grep --color=auto'

# Build aliases
alias cmake-build='cmake --build build'
alias cmake-clean='rm -rf build && mkdir build'
alias make-clean='make clean'

# Git aliases
alias gs='git status'
alias ga='git add'
alias gc='git commit'
alias gp='git push'
alias gl='git log --oneline --graph'
alias gb='git branch -a'

# BCPL specific
alias bcpl-test='./test_bcpl.sh'
alias bcpl-build='./build.sh'
alias bcpl-validate='./validate_build.sh'
EOF
fi

echo "✅ BCPL Compiler development environment setup complete!"
echo ""
echo "🎯 Quick start commands:"
echo "  - bcpl-build    : Build the BCPL compiler"
echo "  - bcpl-test     : Run BCPL tests"
echo "  - bcpl-validate : Validate the build"
echo "  - cmake-build   : Build using CMake"
echo "  - cmake-clean   : Clean CMake build directory"
echo ""
echo "📖 Documentation can be generated with: doxygen"
echo "🔍 Code analysis available with: cppcheck"
echo ""
echo "Happy coding! 🚀"
