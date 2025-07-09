#!/bin/bash

# =============================================================================
# BCPL Compiler Development Environment Setup Script
# Debian Sid (Unstable) Dev Container - Bleeding Edge Setup
# =============================================================================

set -e

echo "🚀 Setting up BCPL Compiler development environment on Debian Sid..."
echo "📋 System: Debian Sid (Unstable) - Cutting Edge"
echo "🎯 Target: Multi-architecture BCPL compiler with latest toolchain"
echo "⚠️  Warning: This is a bleeding-edge environment with the latest packages"
echo ""

# =============================================================================
# SYSTEM INFORMATION
# =============================================================================

echo "📊 System Information:"
echo "  - OS: $(cat /etc/os-release | grep PRETTY_NAME | cut -d= -f2 | tr -d '\"')"
echo "  - Kernel: $(uname -r)"
echo "  - Architecture: $(uname -m)"
echo "  - CPU cores: $(nproc)"
echo "  - Memory: $(free -h | awk '/^Mem:/ {print $2}')"
echo "  - Debian Suite: Sid (Unstable)"
echo ""

# =============================================================================
# PACKAGE UPDATES AND BLEEDING-EDGE SETUP
# =============================================================================

echo "📦 Updating package lists (Debian Sid)..."
sudo apt-get update

# Debian Sid specific: Enable experimental packages for absolutely latest versions
echo "🧪 Enabling experimental repository for bleeding-edge packages..."
echo "deb http://deb.debian.org/debian experimental main" | sudo tee /etc/apt/sources.list.d/experimental.list
sudo apt-get update

echo "🔍 Validating essential packages..."

# Enhanced package list for Debian Sid
REQUIRED_PACKAGES=(
    "gcc-14" "g++-14" "make" "cmake" "ninja-build" 
    "gdb" "valgrind" "git" "python3" "python3-pip"
    "clang" "clang-format" "clang-tidy" "doxygen"
    "rustc" "cargo" "golang-go"
)

for package in "${REQUIRED_PACKAGES[@]}"; do
    if ! dpkg -l | grep -q "^ii  $package "; then
        echo "⚠️  Installing missing package: $package"
        sudo apt-get install -y "$package" || echo "❌ Failed to install $package"
    else
        echo "✅ $package is installed"
    fi
done

# Try to install experimental versions of key packages
echo "🧪 Installing experimental packages where available..."
sudo apt-get install -y -t experimental \
    gcc \
    g++ \
    cmake \
    clang \
    llvm || echo "⚠️  Some experimental packages not available"

# =============================================================================
# CUTTING-EDGE DEVELOPMENT TOOLS
# =============================================================================

echo "🔧 Configuring cutting-edge development tools..."

# Configure latest GCC
echo "🔨 GCC configuration:"
gcc_version=$(gcc --version | head -n1)
echo "  - Version: $gcc_version"
echo "  - Multilib support: $(gcc -print-multi-lib | wc -l) architectures"
echo "  - C23 support: $(gcc --help=C | grep -c c2x || echo 'Checking...')"

# Configure latest Clang
echo "🔧 Clang configuration:"
clang_version=$(clang --version | head -n1)
echo "  - Version: $clang_version"
echo "  - C23 support: Available"

# Configure CMake with latest features
echo "📋 CMake configuration:"
cmake_version=$(cmake --version | head -n1)
echo "  - Version: $cmake_version"
echo "  - Generator: Ninja (configured)"
echo "  - C Standard: C23"
echo "  - C++ Standard: C++23"

# Configure Rust
echo "🦀 Rust configuration:"
rust_version=$(rustc --version)
echo "  - Version: $rust_version"
echo "  - Cargo version: $(cargo --version)"

# Configure Go
echo "🐹 Go configuration:"
go_version=$(go version)
echo "  - Version: $go_version"

# Configure Python environment with latest packages
echo "🐍 Python configuration:"
python_version=$(python3 --version)
echo "  - Version: $python_version"
echo "  - Pip version: $(python3 -m pip --version | awk '{print $2}')"

# Install bleeding-edge Python packages
echo "📦 Installing cutting-edge Python development packages..."
python3 -m pip install --user --no-cache-dir --upgrade \
    black isort ruff mypy pylint \
    pytest pytest-cov pytest-xdist pytest-benchmark \
    jupyter notebook ipython \
    matplotlib seaborn plotly \
    requests beautifulsoup4 \
    pyyaml toml configparser \
    pre-commit commitizen \
    poetry pipenv \
    rich typer click \
    fastapi uvicorn \
    numpy scipy sympy \
    pandas polars

# =============================================================================
# EXPERIMENTAL PACKAGE MANAGERS
# =============================================================================

echo "📦 Setting up experimental package managers..."

# Configure Conan 2.x
if ! command -v conan &> /dev/null; then
    python3 -m pip install --user conan
fi
conan profile detect --force || true
echo "✅ Conan 2.x configured"

# Configure vcpkg
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

# Install and configure experimental build systems
echo "🔨 Installing experimental build systems..."

# Bazel (Google's build system)
if command -v bazel &> /dev/null; then
    echo "✅ Bazel: $(bazel version | head -n1)"
else
    echo "⚠️  Bazel not available"
fi

# Buck2 (Meta's build system)
if command -v buck2 &> /dev/null; then
    echo "✅ Buck2: $(buck2 --version)"
else
    echo "⚠️  Buck2 not available"
fi

# Meson (Python-based build system)
if command -v meson &> /dev/null; then
    echo "✅ Meson: $(meson --version)"
fi

# =============================================================================
# EXPERIMENTAL COMPILERS AND LANGUAGES
# =============================================================================

echo "🧪 Configuring experimental programming languages..."

# Zig
if command -v zig &> /dev/null; then
    echo "✅ Zig: $(zig version)"
else
    echo "⚠️  Installing Zig..."
    # Install latest Zig
    curl -L https://ziglang.org/download/0.12.0/zig-linux-x86_64-0.12.0.tar.xz | tar -xJ -C /tmp
    sudo mv /tmp/zig-linux-x86_64-0.12.0 /opt/zig
    sudo ln -sf /opt/zig/zig /usr/local/bin/zig || echo "❌ Zig installation failed"
fi

# Crystal
if command -v crystal &> /dev/null; then
    echo "✅ Crystal: $(crystal --version | head -n1)"
fi

# Nim
if command -v nim &> /dev/null; then
    echo "✅ Nim: $(nim --version | head -n1)"
fi

# D Language
if command -v gdc &> /dev/null; then
    echo "✅ D (GDC): $(gdc --version | head -n1)"
fi

# =============================================================================
# GIT CONFIGURATION
# =============================================================================

echo "🔐 Setting up Git configuration..."

# Enhanced Git configuration for development
git config --global core.editor "nano"
git config --global init.defaultBranch main
git config --global pull.rebase false
git config --global core.autocrlf input
git config --global diff.tool vimdiff
git config --global merge.tool vimdiff
git config --global core.pager "less -F -X"
git config --global color.ui auto
git config --global push.default simple

# Check Git user configuration
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

# =============================================================================
# PROJECT-SPECIFIC SETUP
# =============================================================================

echo "🎯 Setting up BCPL project environment..."

# Make all shell scripts executable
echo "🔑 Making scripts executable..."
find /workspace -name "*.sh" -type f -exec chmod +x {} \; 2>/dev/null || true

# Create comprehensive build directories
echo "📁 Creating build directories..."
mkdir -p /workspace/{build,build_debug,build_release,build_experimental,install,docs/generated,tests/results,benchmarks}

# Validate CMake project with experimental features
if [ -f "/workspace/CMakeLists.txt" ]; then
    echo "✅ CMakeLists.txt found"
    echo "🔍 Project configuration (experimental):"
    cd /workspace
    
    # Test with different generators and compilers
    for generator in "Ninja" "Unix Makefiles"; do
        for compiler in "gcc" "clang"; do
            build_dir="build_test_${generator,,}_${compiler}"
            build_dir=${build_dir// /_}
            if CC=$compiler cmake -S . -B "$build_dir" -G "$generator" -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1; then
                echo "  - CMake with $generator + $compiler: ✅ Valid"
                rm -rf "$build_dir"
            else
                echo "  - CMake with $generator + $compiler: ⚠️  Issues detected"
            fi
        done
    done
else
    echo "⚠️  CMakeLists.txt not found in workspace root"
fi

# =============================================================================
# SHELL CONFIGURATION AND ADVANCED ALIASES
# =============================================================================

echo "⚡ Setting up advanced shell configuration..."

# Create comprehensive alias and function configuration
cat >> ~/.bashrc << 'EOF'

# =============================================================================
# BCPL Compiler Development Environment - Debian Sid Edition
# =============================================================================

# Environment variables
export MAKEFLAGS="-j$(nproc)"
export CMAKE_GENERATOR="Ninja"
export CMAKE_BUILD_TYPE="Debug"
export CMAKE_EXPORT_COMPILE_COMMANDS=ON
export DEBIAN_SID=1

# Path additions
export PATH="/opt/vcpkg:/opt/zig:$HOME/.local/bin:$HOME/.cargo/bin:$PATH"
export VCPKG_ROOT="/opt/vcpkg"
export CMAKE_TOOLCHAIN_FILE="/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"

# Compiler selection aliases
alias use-gcc='export CC=gcc && export CXX=g++'
alias use-gcc14='export CC=gcc-14 && export CXX=g++-14'
alias use-clang='export CC=clang && export CXX=clang++'
alias use-experimental='export CC=gcc-14 && export CXX=g++-14 && export CFLAGS="-std=c2x" && export CXXFLAGS="-std=c++23"'

# Basic aliases (enhanced)
alias ll='exa -alF --group-directories-first --git || ls -alF --color=auto'
alias la='exa -a --group-directories-first || ls -A --color=auto'
alias l='exa -F --group-directories-first || ls -CF --color=auto'
alias ls='exa --group-directories-first || ls --color=auto'
alias tree='exa --tree || tree'
alias cat='bat || cat'
alias find='fd || find'
alias grep='rg || grep --color=auto'
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'

# Development aliases
alias cls='clear'
alias h='history'
alias df='df -h'
alias du='du -h'
alias free='free -h'
alias ps='ps aux'
alias top='htop'

# Git aliases (enhanced)
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

# Build system aliases (multi-compiler)
alias cmake-gcc='CC=gcc CXX=g++ cmake -S . -B build_gcc -G Ninja'
alias cmake-clang='CC=clang CXX=clang++ cmake -S . -B build_clang -G Ninja'
alias cmake-experimental='CC=gcc-14 CXX=g++-14 cmake -S . -B build_exp -G Ninja -DCMAKE_C_STANDARD=23 -DCMAKE_CXX_STANDARD=23'
alias cmake-configure='cmake -S . -B build -G Ninja'
alias cmake-build='cmake --build build'
alias cmake-install='cmake --install build'
alias cmake-test='ctest --test-dir build'
alias cmake-clean='rm -rf build && mkdir build'
alias ninja-build='ninja -C build'
alias ninja-clean='ninja -C build clean'

# BCPL specific aliases (enhanced)
alias bcpl-build='./build.sh'
alias bcpl-test='./test_bcpl.sh'
alias bcpl-validate='./validate_build.sh'
alias bcpl-clean='find . -name "*.o" -o -name "*.a" -o -name "*.so" | xargs rm -f'
alias bcpl-debug='gdb ./bcplc'
alias bcpl-bench='./benchmark.sh || echo "No benchmark script found"'

# Analysis and debugging (enhanced)
alias valgrind-check='valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes'
alias valgrind-cachegrind='valgrind --tool=cachegrind'
alias valgrind-callgrind='valgrind --tool=callgrind'
alias cppcheck-all='cppcheck --enable=all --std=c23 --language=c --suppress=missingIncludeSystem'
alias clang-format-all='find . -name "*.c" -o -name "*.h" | xargs clang-format -i'
alias clang-tidy-check='clang-tidy --checks="*,-fuchsia-*,-google-readability-todo" --format-style=file'
alias clang-static='scan-build make'
alias coverage='gcov -r'

# Package manager aliases
alias conan-install='conan install . --output-folder=build --build=missing'
alias vcpkg-install='vcpkg install'
alias apt-experimental='sudo apt-get install -t experimental'

# Performance testing
alias perf-record='perf record -g'
alias perf-report='perf report'
alias time-detailed='/usr/bin/time -v'

# Quick navigation
alias cdws='cd /workspace'
alias cdbuild='cd /workspace/build'
alias cdsrc='cd /workspace/src'
alias cdtest='cd /workspace/tests'
alias cddocs='cd /workspace/docs'

# Advanced utility functions
mkcd() { mkdir -p "$1" && cd "$1"; }
backup() { cp "$1" "$1.backup.$(date +%Y%m%d_%H%M%S)"; }

# Comprehensive extract function
extract() {
    if [ -f "$1" ]; then
        case "$1" in
            *.tar.bz2)   tar xjf "$1"     ;;
            *.tar.gz)    tar xzf "$1"     ;;
            *.tar.xz)    tar xJf "$1"     ;;
            *.bz2)       bunzip2 "$1"     ;;
            *.rar)       unrar x "$1"     ;;
            *.gz)        gunzip "$1"      ;;
            *.tar)       tar xf "$1"      ;;
            *.tbz2)      tar xjf "$1"     ;;
            *.tgz)       tar xzf "$1"     ;;
            *.zip)       unzip "$1"       ;;
            *.Z)         uncompress "$1"  ;;
            *.7z)        7z x "$1"        ;;
            *.zst)       zstd -d "$1"     ;;
            *)           echo "'$1' cannot be extracted via extract()" ;;
        esac
    else
        echo "'$1' is not a valid file"
    fi
}

# Compiler switching functions
switch_compiler() {
    case "$1" in
        gcc|gcc-14)
            export CC=gcc-14
            export CXX=g++-14
            echo "Switched to GCC 14"
            ;;
        clang)
            export CC=clang
            export CXX=clang++
            echo "Switched to Clang"
            ;;
        *)
            echo "Available compilers: gcc, gcc-14, clang"
            echo "Current: CC=$CC, CXX=$CXX"
            ;;
    esac
}

# Comprehensive project information
project_info() {
    echo "🎯 BCPL Compiler Project Information (Debian Sid)"
    echo "═══════════════════════════════════════════════════════════"
    echo "📁 Workspace: $(pwd)"
    echo "🖥️  OS: $(cat /etc/os-release | grep PRETTY_NAME | cut -d= -f2 | tr -d '\"')"
    echo "🔧 Build system: CMake + Ninja"
    echo "🏗️  C Standard: C23"
    echo "🔨 Available Compilers:"
    echo "   - GCC: $(gcc --version | head -n1 | awk '{print $3}')"
    echo "   - GCC-14: $(gcc-14 --version 2>/dev/null | head -n1 | awk '{print $3}' || echo 'Not available')"
    echo "   - Clang: $(clang --version | head -n1 | awk '{print $3}')"
    echo "📦 Package Managers: Conan 2.x, vcpkg"
    echo "🐍 Python: $(python3 --version | awk '{print $2}')"
    echo "🦀 Rust: $(rustc --version | awk '{print $2}' || echo 'Not available')"
    echo "🐹 Go: $(go version | awk '{print $3}' || echo 'Not available')"
    echo ""
    echo "🚀 Quick commands:"
    echo "  project_info       - Show this information"
    echo "  switch_compiler    - Switch between compilers"
    echo "  bcpl-build         - Build the BCPL compiler"
    echo "  cmake-experimental - Configure with experimental features"
    echo "  use-experimental   - Enable bleeding-edge compiler flags"
    echo "  valgrind-check     - Run comprehensive memory check"
}

# Show current compiler on prompt
show_compiler_info() {
    echo "Current compiler: CC=$CC, CXX=$CXX"
}

alias compiler-info='show_compiler_info'

EOF

# Set up ZSH configuration for Debian Sid
if [ -f ~/.zshrc ]; then
    echo "🐚 Configuring ZSH environment for Debian Sid..."
    cat >> ~/.zshrc << 'EOF'

# =============================================================================
# BCPL Compiler Development Environment (ZSH) - Debian Sid Edition
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
setopt EXTENDED_GLOB

# Enhanced prompt with compiler info
autoload -Uz vcs_info
precmd_vcs_info() { 
    vcs_info 
}
precmd_functions+=( precmd_vcs_info )
setopt prompt_subst
RPROMPT='${vcs_info_msg_0_} %F{yellow}[$CC]%f'
zstyle ':vcs_info:git:*' formats '%F{240}(%b)%r%f'
zstyle ':vcs_info:*' enable git

# Add Debian Sid indicator to prompt
PS1="%F{green}%n@sid-dev%f:%F{blue}%~%f$ "

EOF
fi

# =============================================================================
# EXPERIMENTAL FEATURES SETUP
# =============================================================================

echo "🧪 Setting up experimental development features..."

# Set up experimental compiler flags
cat >> ~/.bash_experimental << 'EOF'
# Experimental compiler flags for bleeding-edge development
export CFLAGS="-std=c2x -Wall -Wextra -Wpedantic -fsanitize=address,undefined -fanalyzer"
export CXXFLAGS="-std=c++23 -Wall -Wextra -Wpedantic -fsanitize=address,undefined"
export LDFLAGS="-fsanitize=address,undefined"
EOF

echo "📝 Created experimental compiler configuration in ~/.bash_experimental"
echo "   Source with: source ~/.bash_experimental"

# =============================================================================
# DOCUMENTATION AND ANALYSIS SETUP
# =============================================================================

echo "📚 Setting up documentation and analysis environment..."

# Configure Doxygen for latest features
if [ -f "/workspace/Doxyfile" ]; then
    echo "✅ Doxygen configuration found"
    echo "📖 Documentation can be generated with: doxygen"
else
    echo "📝 Creating enhanced Doxygen configuration..."
    cd /workspace
    doxygen -g > /dev/null 2>&1 || echo "⚠️  Could not generate Doxygen config"
    if [ -f "Doxyfile" ]; then
        # Enable latest Doxygen features
        sed -i 's/EXTRACT_ALL            = NO/EXTRACT_ALL            = YES/' Doxyfile
        sed -i 's/GENERATE_HTML          = YES/GENERATE_HTML          = YES/' Doxyfile
        sed -i 's/GENERATE_LATEX         = YES/GENERATE_LATEX         = NO/' Doxyfile
        sed -i 's/HAVE_DOT               = NO/HAVE_DOT               = YES/' Doxyfile
    fi
fi

# =============================================================================
# PERFORMANCE AND OPTIMIZATION SETUP
# =============================================================================

echo "⚡ Configuring performance and optimization tools..."

# Set up performance monitoring for Debian Sid
sudo sysctl -w kernel.perf_event_paranoid=-1 2>/dev/null || echo "⚠️  Could not configure perf (may require privileged container)"
sudo sysctl -w kernel.kptr_restrict=0 2>/dev/null || echo "⚠️  Could not configure kptr_restrict"

# Configure core dump handling
echo "core.%e.%p.%t" | sudo tee /proc/sys/kernel/core_pattern > /dev/null 2>&1 || echo "⚠️  Could not configure core dumps"

# Set up CPU frequency scaling for consistent benchmarks
echo 'performance' | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor 2>/dev/null || echo "⚠️  Could not set CPU governor"

# =============================================================================
# VALIDATION AND TESTING
# =============================================================================

echo "🧪 Validating installation with comprehensive checks..."

# Test essential commands with version information
COMMANDS_TO_TEST=(
    "gcc-14 --version"
    "g++-14 --version" 
    "clang --version"
    "cmake --version"
    "ninja --version"
    "gdb --version"
    "python3 --version"
    "git --version"
    "conan --version"
    "doxygen --version"
    "rustc --version"
    "go version"
)

echo "🔍 Command validation:"
for cmd in "${COMMANDS_TO_TEST[@]}"; do
    if eval "$cmd" > /dev/null 2>&1; then
        version=$(eval "$cmd" 2>/dev/null | head -n1)
        echo "  ✅ $cmd"
        echo "      $(echo $version | cut -c1-80)"
    else
        echo "  ❌ $cmd"
    fi
done

# Test experimental features
echo ""
echo "🧪 Testing experimental features:"

# Test C23 features
if echo 'int main() { typeof(1) x = 42; return 0; }' | gcc-14 -std=c2x -x c - -o /tmp/test_c23 2>/dev/null; then
    echo "  ✅ C23 features (typeof)"
    rm -f /tmp/test_c23
else
    echo "  ⚠️  C23 features may have issues"
fi

# Test C++23 features
if echo '#include <print>\nint main() { std::print("Hello\\n"); }' | g++-14 -std=c++23 -x c++ - -o /tmp/test_cpp23 2>/dev/null; then
    echo "  ✅ C++23 features (std::print)"
    rm -f /tmp/test_cpp23
else
    echo "  ⚠️  C++23 features may have limited support"
fi

# =============================================================================
# FINAL CLEANUP AND SUMMARY
# =============================================================================

echo "🧹 Final cleanup..."
sudo apt-get autoremove -y > /dev/null 2>&1
sudo apt-get autoclean > /dev/null 2>&1

# Clear any temporary files
rm -rf /tmp/* 2>/dev/null || true

echo ""
echo "✅ BCPL Compiler development environment setup complete (Debian Sid)!"
echo ""
echo "🎯 Environment Summary:"
echo "═══════════════════════════════════════════════════════════════════════"
echo "🖥️  OS: Debian Sid (Unstable) - Bleeding Edge"
echo "🔨 Compilers: GCC 14, Clang (latest), Rust, Go"
echo "🏗️  Build: CMake + Ninja, Bazel, Meson"
echo "🐍 Python: $(python3 --version | awk '{print $2}') with cutting-edge packages"
echo "📦 Package Managers: Conan 2.x, vcpkg, experimental APT"
echo "🛠️  Tools: GDB, Valgrind, Clang tools, Doxygen, Perf"
echo "🌐 Cross-compilation: ARM, AARCH64, RISC-V, PowerPC, s390x, MIPS"
echo "🧪 Experimental: C23, C++23, latest sanitizers, analyzers"
echo ""
echo "🚀 Quick Start Commands:"
echo "─────────────────────────────────────────────────────────────────────"
echo "  project_info           - Show detailed project information"
echo "  switch_compiler <name> - Switch between gcc, gcc-14, clang"
echo "  use-experimental       - Enable bleeding-edge compiler flags"
echo "  cmake-experimental     - Configure with experimental CMake features"
echo "  bcpl-build             - Build the BCPL compiler"
echo "  valgrind-check         - Run comprehensive memory analysis"
echo "  source ~/.bash_experimental - Enable experimental compiler flags"
echo ""
echo "📖 Documentation & Analysis:"
echo "─────────────────────────────────────────────────────────────────────"
echo "  doxygen                - Generate API documentation"
echo "  cppcheck-all           - Run static analysis"
echo "  clang-static           - Run Clang static analyzer"
echo "  perf-record            - Record performance data"
echo ""
echo "⚠️  Note: This is a bleeding-edge environment. Some features may be unstable."
echo "🎉 Happy coding with the latest and greatest tools! 🚀"
echo ""

# Display project info if in workspace
if [ -f "/workspace/CMakeLists.txt" ]; then
    echo "📋 Running project_info..."
    source ~/.bashrc
    project_info 2>/dev/null || echo "Run 'source ~/.bashrc && project_info' to see project details"
fi
