#!/bin/bash
set -e

usage() {
    cat <<EOF
Usage: $0 [options]

Options:
  -i, --INSTALL_DIR <dir>     Specify install prefix (default: \$HOME/.local)
  -h, --help                  Show this help message and exit

Examples:
  $0
  $0 -i /opt/myapp
  $0 -b /opt/software/binutils/include
  $0 -i /opt/myapp -b /opt/software/binutils/include
EOF
    exit 1
}

# Defaults
INSTALL_DIR="$HOME/.local"

# Parse arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        -i|--INSTALL_DIR)
            INSTALL_DIR="$2"
            shift 2
            ;;
        -h|--help)
            usage
            ;;
        *)
            echo "Unknown option: $1"
            usage
            ;;
    esac
done

BUILD_DIR=build

# Configure, build, and install
cmake -B "$BUILD_DIR" \
    -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
    .

cmake --build "$BUILD_DIR"
cmake --install "$BUILD_DIR"

echo "Installed to $INSTALL_DIR"

# Check if $INSTALL_DIR/bin is in PATH
if [[ ":$PATH:" != *":$INSTALL_DIR/bin:"* ]]; then
    echo "$INSTALL_DIR/bin is not in your PATH."
    read -p "Do you want to add it to your PATH permanently? (y/n): " add_to_path

    if [[ $add_to_path == "y" || $add_to_path == "Y" ]]; then
        SHELL_CONFIG=""
        if [[ $SHELL == *"bash"* ]]; then
            SHELL_CONFIG="$HOME/.bashrc"
        elif [[ $SHELL == *"zsh"* ]]; then
            SHELL_CONFIG="$HOME/.zshrc"
        elif [[ $SHELL == *"fish"* ]]; then
            SHELL_CONFIG="$HOME/.config/fish/config.fish"
        fi

        if [[ -n $SHELL_CONFIG ]]; then
            echo "export PATH=\"$INSTALL_DIR/bin:\$PATH\"" >> "$SHELL_CONFIG"
            echo "$INSTALL_DIR/bin has been added to your PATH permanently in $SHELL_CONFIG."
        else
            echo "Could not determine your shell configuration file. Please add $INSTALL_DIR/bin to your PATH manually."
        fi
    else
        echo "You chose not to add $INSTALL_DIR/bin to your PATH permanently."
        echo "To use the installed binaries, run: export PATH=\"$INSTALL_DIR/bin:\$PATH\""
    fi
else
    echo "$INSTALL_DIR/bin is already in your PATH."
fi
