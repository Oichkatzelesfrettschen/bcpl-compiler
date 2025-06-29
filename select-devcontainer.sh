#!/bin/bash

# =============================================================================
# BCPL Compiler DevContainer Configuration Selector
# =============================================================================

set -e

echo "🚀 BCPL Compiler Development Environment Setup"
echo "════════════════════════════════════════════════"
echo ""
echo "This project provides two development container configurations:"
echo ""
echo "1. 🛡️  Ubuntu 24.04 LTS (Stable)"
echo "   - Stable, well-tested packages"
echo "   - GCC with C23 support"
echo "   - Recommended for production development"
echo "   - Long-term support and reliability"
echo ""
echo "2. 🧪 Debian Sid (Unstable/Bleeding Edge)"
echo "   - Latest packages and compilers"
echo "   - GCC 14 with full C23/C++23 features"
echo "   - Experimental tools and features"
echo "   - Best for testing cutting-edge functionality"
echo ""

# Function to set up Ubuntu container
setup_ubuntu() {
    echo "🛡️  Setting up Ubuntu 24.04 LTS environment..."
    
    # Ensure Ubuntu is the active container
    if [ -d ".devcontainer-ubuntu" ]; then
        echo "   Moving current .devcontainer to .devcontainer-backup"
        mv .devcontainer .devcontainer-backup 2>/dev/null || true
        echo "   Activating Ubuntu 24.04 configuration"
        cp -r .devcontainer-ubuntu .devcontainer
    elif [ ! -d ".devcontainer" ]; then
        echo "   ERROR: Ubuntu configuration not found!"
        exit 1
    fi
    
    echo "✅ Ubuntu 24.04 LTS environment ready"
    echo "   Use: 'Reopen in Container' in VS Code"
}

# Function to set up Debian container
setup_debian() {
    echo "🧪 Setting up Debian Sid (Unstable) environment..."
    
    # Ensure Debian is the active container
    if [ -d ".devcontainer-debian" ]; then
        echo "   Moving current .devcontainer to .devcontainer-backup"
        mv .devcontainer .devcontainer-backup 2>/dev/null || true
        echo "   Activating Debian Sid configuration"
        cp -r .devcontainer-debian .devcontainer
    else
        echo "   ERROR: Debian configuration not found!"
        exit 1
    fi
    
    echo "✅ Debian Sid environment ready"
    echo "   ⚠️  Warning: This is a bleeding-edge environment"
    echo "   Use: 'Reopen in Container' in VS Code"
}

# Function to show current configuration
show_current() {
    echo "🔍 Current Configuration Analysis"
    echo "─────────────────────────────────"
    
    if [ -f ".devcontainer/devcontainer.json" ]; then
        if grep -q "Ubuntu 24.04" .devcontainer/devcontainer.json; then
            echo "   Current: 🛡️  Ubuntu 24.04 LTS"
        elif grep -q "Debian Sid" .devcontainer/devcontainer.json; then
            echo "   Current: 🧪 Debian Sid (Unstable)"
        else
            echo "   Current: ❓ Unknown configuration"
        fi
    else
        echo "   Current: ❌ No devcontainer configuration found"
    fi
    
    echo ""
    echo "Available configurations:"
    [ -d ".devcontainer-ubuntu" ] && echo "   ✅ Ubuntu 24.04 LTS available"
    [ -d ".devcontainer-debian" ] && echo "   ✅ Debian Sid available"
    echo ""
}

# Function to show detailed comparison
show_comparison() {
    echo "📊 Detailed Comparison"
    echo "══════════════════════"
    echo ""
    echo "🛡️  Ubuntu 24.04 LTS"
    echo "   ✅ Stability: High"
    echo "   ✅ Package reliability: Excellent"
    echo "   ✅ Long-term support: 5 years"
    echo "   ✅ Production ready: Yes"
    echo "   ✅ C23 support: Good"
    echo "   ✅ Cross-compilation: Standard toolchains"
    echo "   ⚠️  Package versions: Stable (may be older)"
    echo ""
    echo "🧪 Debian Sid (Unstable)"
    echo "   ✅ Latest packages: Always current"
    echo "   ✅ GCC 14: Full C23/C++23 support"
    echo "   ✅ Experimental features: Extensive"
    echo "   ✅ Development tools: Cutting-edge"
    echo "   ✅ Cross-compilation: Latest toolchains"
    echo "   ⚠️  Stability: Variable (bleeding-edge)"
    echo "   ⚠️  Package conflicts: Possible"
    echo ""
    echo "🎯 Recommendations:"
    echo "   - Ubuntu: Production development, team collaboration"
    echo "   - Debian Sid: Experimental features, latest C23 testing"
    echo ""
}

# Function to backup current configuration
backup_config() {
    if [ -d ".devcontainer" ]; then
        backup_name=".devcontainer-backup-$(date +%Y%m%d_%H%M%S)"
        echo "💾 Backing up current configuration to $backup_name"
        cp -r .devcontainer "$backup_name"
        echo "✅ Backup created"
    fi
}

# Interactive menu
show_menu() {
    while true; do
        echo ""
        echo "🎛️  Configuration Menu"
        echo "─────────────────────"
        echo "1) 🛡️  Switch to Ubuntu 24.04 LTS"
        echo "2) 🧪 Switch to Debian Sid"
        echo "3) 🔍 Show current configuration"
        echo "4) 📊 Show detailed comparison"
        echo "5) 💾 Backup current configuration"
        echo "6) ❌ Exit"
        echo ""
        read -p "Select an option (1-6): " choice
        
        case $choice in
            1)
                backup_config
                setup_ubuntu
                break
                ;;
            2)
                backup_config
                setup_debian
                break
                ;;
            3)
                show_current
                ;;
            4)
                show_comparison
                ;;
            5)
                backup_config
                ;;
            6)
                echo "👋 Goodbye!"
                exit 0
                ;;
            *)
                echo "❌ Invalid option. Please choose 1-6."
                ;;
        esac
    done
}

# Main execution
main() {
    # Check if we're in the right directory
    if [ ! -f "CMakeLists.txt" ] && [ ! -f "bcplc" ]; then
        echo "❌ Error: This script should be run from the BCPL compiler project root"
        echo "   Please cd to the project directory and try again"
        exit 1
    fi
    
    # Show current status
    show_current
    
    # Check command line arguments
    case "${1:-}" in
        ubuntu|stable)
            backup_config
            setup_ubuntu
            ;;
        debian|sid|unstable)
            backup_config
            setup_debian
            ;;
        status|current)
            show_current
            exit 0
            ;;
        compare|comparison)
            show_comparison
            exit 0
            ;;
        help|-h|--help)
            echo "Usage: $0 [ubuntu|debian|status|compare|help]"
            echo ""
            echo "Commands:"
            echo "  ubuntu    - Switch to Ubuntu 24.04 LTS"
            echo "  debian    - Switch to Debian Sid"
            echo "  status    - Show current configuration"
            echo "  compare   - Show detailed comparison"
            echo "  help      - Show this help"
            echo ""
            echo "Interactive mode:"
            echo "  $0        - Show interactive menu"
            exit 0
            ;;
        "")
            # No arguments, show interactive menu
            show_menu
            ;;
        *)
            echo "❌ Unknown option: $1"
            echo "   Use '$0 help' for usage information"
            exit 1
            ;;
    esac
}

main "$@"
