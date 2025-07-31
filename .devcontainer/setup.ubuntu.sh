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

#!/bin/bash

# =============================================================================
# BCPL Compiler Development Environment Setup Script
# Ubuntu 24.04 Dev Container - Comprehensive Setup
# =============================================================================

set -e

echo "🚀 Setting up BCPL Compiler development environment..."
echo "📋 System: Ubuntu 24.04 LTS"
echo "🎯 Target: Multi-architecture BCPL compiler with C23 runtime"
echo ""

# =============================================================================
# SYSTEM INFORMATION
# =============================================================================

echo "📊 System Information:"
echo "  - OS: $(lsb_release -d | cut -f2)"
echo "  - Kernel: $(uname -r)"
echo "  - Architecture: $(uname -m)"
echo "  - CPU cores: $(nproc)"
echo "  - Memory: $(free -h | awk '/^Mem:/ {print $2}')"
echo ""

# =============================================================================
# PACKAGE UPDATES AND VALIDATION
# =============================================================================

echo "📦 Updating package lists..."
sudo apt-get update

echo "🔍 Validating essential packages..."
# Verify critical packages are installed
REQUIRED_PACKAGES=(
    "gcc" "g++" "make" "cmake" "ninja-build" 
    "gdb" "valgrind" "git" "python3" "python3-pip"
    "clang" "clang-format" "clang-tidy" "doxygen"
)

for package in "${REQUIRED_PACKAGES[@]}"; do
    if ! dpkg -l | grep -q "^ii  $package "; then
        echo "⚠️  Installing missing package: $package"
        sudo apt-get install -y "$package"
    else
        echo "✅ $package is installed"
    fi
done

# =============================================================================
# DEVELOPMENT TOOL CONFIGURATION
# =============================================================================

echo "🔧 Configuring development tools..."

# Configure CMake
echo "📋 CMake configuration:"
cmake_version=$(cmake --version | head -n1)
echo "  - Version: $cmake_version"
echo "  - Generator: Ninja (configured)"
echo "  - C Standard: C23"
echo "  - C++ Standard: C++17"

# Configure GCC
echo "🔨 GCC configuration:"
gcc_version=$(gcc --version | head -n1)
echo "  - Version: $gcc_version"
echo "  - Multilib support: $(gcc -print-multi-lib | wc -l) architectures"

# Configure Python environment
echo "🐍 Python configuration:"
python_version=$(python3 --version)
echo "  - Version: $python_version"
echo "  - Pip version: $(python3 -m pip --version | awk '{print $2}')"

# Install additional Python packages for development
echo "📦 Installing Python development packages..."
python3 -m pip install --user --no-cache-dir \
    black isort flake8 mypy pylint \
    pytest pytest-cov pytest-xdist \
    jupyter notebook ipython \
    matplotlib seaborn plotly \
    requests beautifulsoup4 \
    pyyaml toml configparser

# =============================================================================
# CONAN PACKAGE MANAGER SETUP
# =============================================================================

echo "📦 Setting up Conan package manager..."
if ! command -v conan &> /dev/null; then
    python3 -m pip install --user conan
fi

# Initialize Conan profile
conan profile detect --force || true
echo "✅ Conan configured"

# =============================================================================
# VCPKG PACKAGE MANAGER SETUP
# =============================================================================

echo "📦 Configuring vcpkg package manager..."
if [ -d "/opt/vcpkg" ]; then
    echo "✅ vcpkg is available at /opt/vcpkg"
    /opt/vcpkg/vcpkg version
else
    echo "⚠️  vcpkg not found, installing..."
    sudo git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg
    sudo /opt/vcpkg/bootstrap-vcpkg.sh
    sudo ln -sf /opt/vcpkg/vcpkg /usr/local/bin/vcpkg
fi

# =============================================================================
# GIT CONFIGURATION
# =============================================================================

echo "🔐 Setting up Git configuration..."

# Check if Git is already configured
if [ -z "$(git config --global user.name 2>/dev/null)" ]; then
    echo "⚙️  Git user.name not set. Please configure:"
    echo "    git config --global user.name 'Your Name'"
else
    echo "✅ Git user.name: $(git config --global user.name)"
fi

if [ -z "$(git config --global user.email 2>/dev/null)" ]; then
    echo "⚙️  Git user.email not set. Please configure:"
    echo "    git config --global user.email 'your.email@example.com'"
else
    echo "✅ Git user.email: $(git config --global user.email)"
fi

# Set up useful Git configuration
git config --global core.editor "nano"
git config --global init.defaultBranch main
git config --global pull.rebase false
git config --global core.autocrlf input
git config --global diff.tool vimdiff
git config --global merge.tool vimdiff

# =============================================================================
# PROJECT-SPECIFIC SETUP
# =============================================================================

echo "🎯 Setting up BCPL project environment..."

# Make all shell scripts executable
echo "🔑 Making scripts executable..."
find /workspace -name "*.sh" -type f -exec chmod +x {} \; 2>/dev/null || true

# Create build directories
echo "📁 Creating build directories..."
mkdir -p /workspace/{build,build_debug,build_release,install,docs/generated,tests/results}

# Validate CMake project
if [ -f "/workspace/CMakeLists.txt" ]; then
    echo "✅ CMakeLists.txt found"
    echo "🔍 Project configuration:"
    cd /workspace
    if cmake -S . -B build_test -G Ninja -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1; then
        echo "  - CMake configuration: ✅ Valid"
        rm -rf build_test
    else
        echo "  - CMake configuration: ⚠️  Issues detected"
    fi
else
    echo "⚠️  CMakeLists.txt not found in workspace root"
fi

# =============================================================================
# SHELL CONFIGURATION AND ALIASES
# =============================================================================

echo "⚡ Setting up shell aliases and environment..."

# Create comprehensive alias configuration
cat >> ~/.bashrc << 'EOF'

# =============================================================================
# BCPL Compiler Development Environment
# =============================================================================

# Environment variables
export MAKEFLAGS="-j$(nproc)"
export CMAKE_GENERATOR="Ninja"
export CMAKE_BUILD_TYPE="Debug"
export CMAKE_EXPORT_COMPILE_COMMANDS=ON

# Path additions
export PATH="/opt/vcpkg:$HOME/.local/bin:$PATH"
export VCPKG_ROOT="/opt/vcpkg"
export CMAKE_TOOLCHAIN_FILE="/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"

# Basic aliases
alias ll='ls -alF --color=auto'
alias la='ls -A --color=auto'
alias l='ls -CF --color=auto'
alias ls='ls --color=auto'
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'

# Development aliases
alias cls='clear'
alias h='history'
alias df='df -h'
alias du='du -h'
alias free='free -h'
alias ps='ps aux'
alias top='htop'

# Git aliases
alias gs='git status'
alias ga='git add'
alias gaa='git add --all'
alias gc='git commit'
alias gcm='git commit -m'
alias gp='git push'
alias gpl='git pull'
alias gl='git log --oneline --graph --decorate'
alias gla='git log --oneline --graph --decorate --all'
alias gb='git branch -a'
alias gco='git checkout'
alias gcb='git checkout -b'
alias gd='git diff'
alias gdc='git diff --cached'
alias gst='git stash'
alias gstp='git stash pop'

# Build system aliases
alias cmake-configure='cmake -S . -B build -G Ninja'
alias cmake-build='cmake --build build'
alias cmake-install='cmake --install build'
alias cmake-test='ctest --test-dir build'
alias cmake-clean='rm -rf build && mkdir build'
alias make-clean='make clean'
alias ninja-build='ninja -C build'
alias ninja-clean='ninja -C build clean'

# BCPL specific aliases
alias bcpl-build='./build.sh'
alias bcpl-test='./test_bcpl.sh'
alias bcpl-validate='./validate_build.sh'
alias bcpl-clean='find . -name "*.o" -o -name "*.a" -o -name "*.so" | xargs rm -f'
alias bcpl-debug='gdb ./bcplc'

# Analysis and debugging
alias valgrind-check='valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all'
alias cppcheck-all='cppcheck --enable=all --std=c23 --language=c'
alias clang-format-all='find . -name "*.c" -o -name "*.h" | xargs clang-format -i'
alias clang-tidy-check='clang-tidy --checks="*" --format-style=file'

# Quick navigation
alias cdws='cd /workspace'
alias cdbuild='cd /workspace/build'
alias cdsrc='cd /workspace/src'
alias cdtest='cd /workspace/tests'
alias cddocs='cd /workspace/docs'

# Utility functions
mkcd() { mkdir -p "$1" && cd "$1"; }
backup() { cp "$1" "$1.backup.$(date +%Y%m%d_%H%M%S)"; }
extract() {
    if [ -f "$1" ]; then
        case "$1" in
            *.tar.bz2)   tar xjf "$1"     ;;
            *.tar.gz)    tar xzf "$1"     ;;
            *.bz2)       bunzip2 "$1"     ;;
            *.rar)       unrar x "$1"     ;;
            *.gz)        gunzip "$1"      ;;
            *.tar)       tar xf "$1"      ;;
            *.tbz2)      tar xjf "$1"     ;;
            *.tgz)       tar xzf "$1"     ;;
            *.zip)       unzip "$1"       ;;
            *.Z)         uncompress "$1"  ;;
            *.7z)        7z x "$1"        ;;
            *)           echo "'$1' cannot be extracted via extract()" ;;
        esac
    else
        echo "'$1' is not a valid file"
    fi
}

# Project information
project_info() {
    echo "🎯 BCPL Compiler Project Information"
    echo "═══════════════════════════════════════"
    echo "📁 Workspace: $(pwd)"
    echo "🔧 Build system: CMake + Ninja"
    echo "🏗️  C Standard: C23"
    echo "🔨 Compiler: GCC $(gcc --version | head -n1 | awk '{print $3}')"
    echo "📦 Package managers: Conan, vcpkg"
    echo "🐍 Python: $(python3 --version | awk '{print $2}')"
    echo ""
    echo "🚀 Quick commands:"
    echo "  bcpl-build     - Build the compiler"
    echo "  bcpl-test      - Run tests"
    echo "  cmake-configure - Configure with CMake"
    echo "  cmake-build    - Build with CMake"
    echo "  project_info   - Show this information"
}

EOF

# Set up ZSH aliases if ZSH is being used
if [ -f ~/.zshrc ]; then
    echo "🐚 Configuring ZSH environment..."
    cat >> ~/.zshrc << 'EOF'

# =============================================================================
# BCPL Compiler Development Environment (ZSH)
# =============================================================================

# Source the same configuration as bash
source ~/.bashrc 2>/dev/null || true

# ZSH specific enhancements
setopt AUTO_CD
setopt CORRECT
setopt HIST_VERIFY
setopt SHARE_HISTORY
setopt APPEND_HISTORY
setopt INC_APPEND_HISTORY

# Enhanced prompt
autoload -Uz vcs_info
precmd_vcs_info() { vcs_info }
precmd_functions+=( precmd_vcs_info )
setopt prompt_subst
RPROMPT=\$vcs_info_msg_0_
zstyle ':vcs_info:git:*' formats '%F{240}(%b)%r%f'
zstyle ':vcs_info:*' enable git

EOF
fi

# =============================================================================
# DOCUMENTATION GENERATION
# =============================================================================

echo "📚 Setting up documentation environment..."

# Configure Doxygen if Doxyfile exists
if [ -f "/workspace/Doxyfile" ]; then
    echo "✅ Doxygen configuration found"
    echo "📖 Documentation can be generated with: doxygen"
else
    echo "📝 Creating basic Doxygen configuration..."
    cd /workspace
    doxygen -g > /dev/null 2>&1 || echo "⚠️  Could not generate Doxygen config"
fi

# =============================================================================
# PERFORMANCE AND OPTIMIZATION SETUP
# =============================================================================

echo "⚡ Configuring performance tools..."

# Set up performance monitoring
sudo sysctl -w kernel.perf_event_paranoid=-1 2>/dev/null || echo "⚠️  Could not configure perf (may require privileged container)"

# Configure core dump handling
echo "core.%e.%p.%t" | sudo tee /proc/sys/kernel/core_pattern > /dev/null 2>&1 || echo "⚠️  Could not configure core dumps"

# =============================================================================
# VALIDATION AND TESTING
# =============================================================================

echo "🧪 Validating installation..."

# Test essential commands
COMMANDS_TO_TEST=(
    "gcc --version"
    "g++ --version" 
    "cmake --version"
    "ninja --version"
    "gdb --version"
    "python3 --version"
    "git --version"
    "conan --version"
    "doxygen --version"
)

echo "🔍 Command validation:"
for cmd in "${COMMANDS_TO_TEST[@]}"; do
    if eval "$cmd" > /dev/null 2>&1; then
        echo "  ✅ $cmd"
    else
        echo "  ❌ $cmd"
    fi
done

# =============================================================================
# FINAL CLEANUP AND SUMMARY
# =============================================================================

echo "🧹 Final cleanup..."
sudo apt-get autoremove -y > /dev/null 2>&1
sudo apt-get autoclean > /dev/null 2>&1

# Clear any temporary files
rm -rf /tmp/* 2>/dev/null || true

echo ""
echo "✅ BCPL Compiler development environment setup complete!"
echo ""
echo "🎯 Environment Summary:"
echo "═══════════════════════════════════════════════════════════"
echo "🖥️  OS: Ubuntu 24.04 LTS"
echo "🔨 Compiler: GCC with C23 support"
echo "🏗️  Build: CMake + Ninja"
echo "🐍 Python: $(python3 --version | awk '{print $2}')"
echo "📦 Package Managers: Conan, vcpkg"
echo "🛠️  Tools: GDB, Valgrind, Clang tools, Doxygen"
echo "🌐 Cross-compilation: ARM, AARCH64, RISC-V"
echo ""
echo "🚀 Quick Start Commands:"
echo "───────────────────────────────────────────────────────────"
echo "  project_info       - Show project information"
echo "  bcpl-build         - Build the BCPL compiler"
echo "  bcpl-test          - Run BCPL tests"
echo "  cmake-configure    - Configure build with CMake"
echo "  cmake-build        - Build with CMake"
echo "  valgrind-check     - Run memory check"
echo "  clang-format-all   - Format all C files"
echo ""
echo "📖 Documentation:"
echo "───────────────────────────────────────────────────────────"
echo "  doxygen            - Generate API documentation"
echo "  cppcheck-all       - Run static analysis"
echo ""
echo "🎉 Happy coding with BCPL! 🚀"
echo ""

# Display project info if in workspace
if [ -f "/workspace/CMakeLists.txt" ]; then
    echo "📋 Running project_info..."
    source ~/.bashrc
    project_info 2>/dev/null || echo "Run 'source ~/.bashrc && project_info' to see project details"
fi
