#!/bin/bash
INSTALL_DIR=${1:-$HOME/.local}
BUILD_DIR=build

# Configure, build, and install
cmake -B $BUILD_DIR -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR .
cmake --build $BUILD_DIR
cmake --install $BUILD_DIR

echo "Installed to $INSTALL_DIR"
