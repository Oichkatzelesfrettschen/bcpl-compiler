#!/bin/bash

# =============================================================================
# BCPL Compiler DevContainer Validation Script
# =============================================================================

set -e

echo "🔍 BCPL Compiler DevContainer Configuration Validation"
echo "════════════════════════════════════════════════════════"
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Validation functions
validate_file() {
    local file="$1"
    local description="$2"
    
    if [ -f "$file" ]; then
        echo -e "${GREEN}✅${NC} $description: $file"
        return 0
    else
        echo -e "${RED}❌${NC} $description: $file (missing)"
        return 1
    fi
}

validate_dir() {
    local dir="$1"
    local description="$2"
    
    if [ -d "$dir" ]; then
        echo -e "${GREEN}✅${NC} $description: $dir"
        return 0
    else
        echo -e "${RED}❌${NC} $description: $dir (missing)"
        return 1
    fi
}

validate_executable() {
    local file="$1"
    local description="$2"
    
    if [ -x "$file" ]; then
        echo -e "${GREEN}✅${NC} $description: $file (executable)"
        return 0
    else
        echo -e "${YELLOW}⚠️${NC} $description: $file (not executable)"
        return 1
    fi
}

# Main validation
main() {
    local errors=0
    
    echo "📁 Directory Structure Validation"
    echo "─────────────────────────────────"
    
    # Check main directories
    validate_dir ".devcontainer" "Ubuntu 24.04 container" || ((errors++))
    validate_dir ".devcontainer-debian" "Debian Sid container" || ((errors++))
    validate_dir ".devcontainer-ubuntu" "Ubuntu backup container" || ((errors++))
    
    echo ""
    echo "📄 Ubuntu 24.04 Container Files"
    echo "─────────────────────────────────"
    
    # Ubuntu container files
    validate_file ".devcontainer/devcontainer.json" "DevContainer config" || ((errors++))
    validate_file ".devcontainer/Dockerfile" "Ubuntu Dockerfile" || ((errors++))
    validate_file ".devcontainer/setup.sh" "Ubuntu setup script" || ((errors++))
    validate_file ".devcontainer/README.md" "Ubuntu documentation" || ((errors++))
    
    # Check if setup script is executable
    validate_executable ".devcontainer/setup.sh" "Ubuntu setup script"
    
    echo ""
    echo "📄 Debian Sid Container Files"
    echo "─────────────────────────────────"
    
    # Debian container files
    validate_file ".devcontainer-debian/devcontainer.json" "DevContainer config" || ((errors++))
    validate_file ".devcontainer-debian/Dockerfile" "Debian Dockerfile" || ((errors++))
    validate_file ".devcontainer-debian/setup.sh" "Debian setup script" || ((errors++))
    validate_file ".devcontainer-debian/README.md" "Debian documentation" || ((errors++))
    
    # Check if setup script is executable
    validate_executable ".devcontainer-debian/setup.sh" "Debian setup script"
    
    echo ""
    echo "🔧 Configuration Scripts"
    echo "────────────────────────"
    
    # Configuration scripts
    validate_file "select-devcontainer.sh" "Container selector script" || ((errors++))
    validate_file "DEVCONTAINER_SETUP.md" "Setup documentation" || ((errors++))
    
    # Check if selector script is executable
    validate_executable "select-devcontainer.sh" "Container selector script"
    
    echo ""
    echo "🔍 Configuration Content Validation"
    echo "───────────────────────────────────"
    
    # Check Ubuntu container configuration
    if [ -f ".devcontainer/devcontainer.json" ]; then
        if grep -q "Ubuntu 24.04" ".devcontainer/devcontainer.json"; then
            echo -e "${GREEN}✅${NC} Ubuntu container properly configured"
        else
            echo -e "${RED}❌${NC} Ubuntu container configuration issue"
            ((errors++))
        fi
    fi
    
    # Check Debian container configuration
    if [ -f ".devcontainer-debian/devcontainer.json" ]; then
        if grep -q "Debian Sid" ".devcontainer-debian/devcontainer.json"; then
            echo -e "${GREEN}✅${NC} Debian container properly configured"
        else
            echo -e "${RED}❌${NC} Debian container configuration issue"
            ((errors++))
        fi
    fi
    
    # Check Dockerfile content
    if [ -f ".devcontainer/Dockerfile" ]; then
        if grep -q "ubuntu-24.04" ".devcontainer/Dockerfile"; then
            echo -e "${GREEN}✅${NC} Ubuntu Dockerfile uses correct base image"
        else
            echo -e "${YELLOW}⚠️${NC} Ubuntu Dockerfile base image check failed"
        fi
    fi
    
    if [ -f ".devcontainer-debian/Dockerfile" ]; then
        if grep -q "debian:sid" ".devcontainer-debian/Dockerfile"; then
            echo -e "${GREEN}✅${NC} Debian Dockerfile uses correct base image"
        else
            echo -e "${YELLOW}⚠️${NC} Debian Dockerfile base image check failed"
        fi
    fi
    
    echo ""
    echo "📦 Package Configuration Check"
    echo "─────────────────────────────"
    
    # Check for essential packages in setup scripts
    essential_packages=("gcc" "cmake" "ninja-build" "gdb" "valgrind" "git")
    
    for package in "${essential_packages[@]}"; do
        if grep -q "$package" ".devcontainer/setup.sh" 2>/dev/null; then
            echo -e "${GREEN}✅${NC} Ubuntu setup includes $package"
        else
            echo -e "${YELLOW}⚠️${NC} Ubuntu setup may be missing $package"
        fi
        
        if grep -q "$package" ".devcontainer-debian/setup.sh" 2>/dev/null; then
            echo -e "${GREEN}✅${NC} Debian setup includes $package"
        else
            echo -e "${YELLOW}⚠️${NC} Debian setup may be missing $package"
        fi
    done
    
    echo ""
    echo "🎯 Summary"
    echo "─────────"
    
    if [ $errors -eq 0 ]; then
        echo -e "${GREEN}🎉 All validations passed!${NC}"
        echo -e "${GREEN}✅ DevContainer configurations are ready for use${NC}"
        echo ""
        echo "🚀 Next steps:"
        echo "  1. Run: ./select-devcontainer.sh"
        echo "  2. Choose your preferred environment"
        echo "  3. Open VS Code and 'Reopen in Container'"
        echo "  4. Start developing!"
    else
        echo -e "${RED}❌ Validation failed with $errors error(s)${NC}"
        echo -e "${YELLOW}⚠️  Please check the missing files/configurations above${NC}"
        exit 1
    fi
    
    echo ""
    echo "📊 Configuration Overview:"
    echo "  🛡️  Ubuntu 24.04 LTS: Stable, production-ready"
    echo "  🧪 Debian Sid: Bleeding-edge, experimental"
    echo "  🔄 Easy switching with select-devcontainer.sh"
    echo "  📚 Complete documentation in README files"
}

# Run validation
main "$@"
