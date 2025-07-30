#!/bin/bash
# BCPL Compiler DevContainer configuration selector
set -e
BASE_DIR=".devcontainer"

set_variant() {
    local variant="$1"
    case "$variant" in
        ubuntu|debian)
            ln -sf "Dockerfile.${variant}" "${BASE_DIR}/Dockerfile"
            ln -sf "setup.${variant}.sh" "${BASE_DIR}/setup.sh"
            ln -sf "devcontainer.${variant}.json" "${BASE_DIR}/devcontainer.json"
            echo "Switched to $variant configuration."
            ;;
        *)
            echo "Unknown variant: $variant" >&2
            exit 1
            ;;
    esac
}

show_status() {
    if grep -q "Debian Sid" "${BASE_DIR}/devcontainer.json"; then
        echo "Current configuration: debian"
    elif grep -q "Ubuntu 24.04" "${BASE_DIR}/devcontainer.json"; then
        echo "Current configuration: ubuntu"
    else
        echo "Current configuration: unknown"
    fi
}

show_help() {
    cat <<'HLP'
Usage: ./select-devcontainer.sh [ubuntu|debian|status|help]
Switch development container configuration.
Commands:
  ubuntu   Use Ubuntu 24.04 container
  debian   Use Debian Sid container
  status   Display current configuration
  help     Show this message
HLP
}

case "${1:-}" in
    ubuntu|debian)
        set_variant "$1"
        ;;
    status)
        show_status
        ;;
    help|-h|--help|"")
        show_help
        ;;
    *)
        echo "Invalid argument: $1" >&2
        show_help
        exit 1
        ;;
esac
