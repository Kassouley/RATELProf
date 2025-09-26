#!/bin/bash
set -e

usage() {
    cat <<EOF
Usage: $0 <sett.config>

Arguments:
  sett.config       JSON file containing build options

Example JSON:
{
  "hip_include_dir": "/opt/rocm/include",
  "hsa_include_dir": "/opt/rocm/include",
  "omp_include_dir": "/opt/rocm/llvm/include",
  "mpi_include_dir": "/usr/include",
  "install_dir": "/opt/myapp",
  "check_symbol_verbose": true,
  "plugin_stdout": false,
  "plugin_msgpack": true,
}
EOF
    exit 1
}

# Check if JSON file is provided
if [[ $# -gt 1 ]]; then
    usage
fi

CONFIG_FILE="${1:-./sett.config}"

if [[ ! -f "$CONFIG_FILE" ]]; then
    echo "Error: JSON config file '$CONFIG_FILE' not found."
    usage
fi

# Function to parse a JSON string value (removes quotes and spaces)
get_json_value() {
    local key="$1"
    grep -oP "\"$key\"\s*:\s*\K\"?[^\",\"}]*\"?" "$CONFIG_FILE" | tr -d '"'
}

# Read values from JSON
INSTALL_DIR=$(get_json_value "install_dir")
HIP_INCLUDE_DIR=$(get_json_value "hip_include_dir")
HSA_INCLUDE_DIR=$(get_json_value "hsa_include_dir")
OMP_INCLUDE_DIR=$(get_json_value "omp_include_dir")
MPI_INCLUDE_DIR=$(get_json_value "mpi_include_dir")
HIPCC_COMPILER=$(get_json_value "hipcc_compiler")
NEED_PLUGIN_STDOUT=$(get_json_value "plugin_stdout")
NEED_PLUGIN_MSGPACK=$(get_json_value "plugin_msgpack")
CHECK_SYMBOL_VERBOSE=$(get_json_value "check_symbol_verbose")

# Set default install dir if not in JSON
INSTALL_DIR="${INSTALL_DIR:-$HOME/.local}"/ratelprof

BUILD_DIR=build

# Configure cmake options
CMAKE_OPTIONS="-DCMAKE_INSTALL_PREFIX=$INSTALL_DIR"
CMAKE_ENV=""

[[ -n "$HIP_INCLUDE_DIR" ]] && CMAKE_ENV="$CMAKE_ENV HIP_INCLUDE_DIR=$HIP_INCLUDE_DIR"
[[ -n "$HSA_INCLUDE_DIR" ]] && CMAKE_ENV="$CMAKE_ENV HSA_INCLUDE_DIR=$HSA_INCLUDE_DIR"
[[ -n "$OMP_INCLUDE_DIR" ]] && CMAKE_ENV="$CMAKE_ENV OMP_INCLUDE_DIR=$OMP_INCLUDE_DIR"
[[ -n "$MPI_INCLUDE_DIR" ]] && CMAKE_ENV="$CMAKE_ENV MPI_INCLUDE_DIR=$MPI_INCLUDE_DIR"
[[ -n "$HIPCC_COMPILER"  ]] && CMAKE_ENV="$CMAKE_ENV HIPCC_COMPILER=$HIPCC_COMPILER"
[[ "$NEED_PLUGIN_STDOUT"   == "true"  ]] && CMAKE_ENV="$CMAKE_ENV NEED_PLUGIN_STDOUT=ON"
[[ "$NEED_PLUGIN_MSGPACK"  == "true"  ]] && CMAKE_ENV="$CMAKE_ENV NEED_PLUGIN_MSGPACK=ON"
[[ "$CHECK_SYMBOL_VERBOSE" == "false" ]] && CMAKE_ENV="$CMAKE_ENV CHECK_SYMBOL_VERBOSE=ON"

# Run CMake
eval "$CMAKE_ENV cmake -B \"$BUILD_DIR\" $CMAKE_OPTIONS ."
cmake --build "$BUILD_DIR"
cmake --install "$BUILD_DIR"

echo "Installed to $INSTALL_DIR"

# Normalize the path (remove trailing slash)
BIN_DIR="${INSTALL_DIR%/}/bin"

# Check if BIN_DIR is in PATH
case ":$PATH:" in
  *":$BIN_DIR:"*)
    echo "$BIN_DIR is already in your PATH."
    ;;
  *)
    echo "$BIN_DIR is not in your PATH."
    read -p "Do you want to add it to your PATH permanently? (y/n): " add_to_path

    if [[ $add_to_path == [Yy] ]]; then
        SHELL_CONFIG=""
        case "$SHELL" in
            *bash*) SHELL_CONFIG="$HOME/.bashrc" ;;
            *zsh*)  SHELL_CONFIG="$HOME/.zshrc" ;;
            *fish*) SHELL_CONFIG="$HOME/.config/fish/config.fish" ;;
        esac

        if [[ -n $SHELL_CONFIG ]]; then
            echo "export PATH=\"$BIN_DIR:\$PATH\"" >> "$SHELL_CONFIG"
            echo "$BIN_DIR has been added to your PATH permanently in $SHELL_CONFIG."
        else
            echo "Could not determine your shell configuration file. Please add $BIN_DIR to your PATH manually."
        fi
    else
        echo "You chose not to add $BIN_DIR to your PATH permanently."
        echo "To use the installed binaries, run: export PATH=\"$BIN_DIR:\$PATH\""
    fi
    ;;
esac

