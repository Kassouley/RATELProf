#!/bin/bash
INSTALL_DIR=${1:-$HOME/.local}
BUILD_DIR=build

set -e

# Configure, build, and install
cmake -B $BUILD_DIR -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR .
cmake --build $BUILD_DIR 
cmake --install $BUILD_DIR

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
            echo "export PATH=\"$INSTALL_DIR/bin:\$PATH\"" >> $SHELL_CONFIG
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
