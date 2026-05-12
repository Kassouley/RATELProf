#!/bin/bash

# Function to display help message
function display_help() {
    cat << EOF
Usage: ratelprof [--help] <command> [options] [command args] 

Commands:
  profile       Run an application and capture its profile into a RProf-Rep report.
  stats         Generate statistics reports from from an input RProf-Rep report.
  analyze       Generate analyze reports from an input RProf-Rep report.
  breakdown     Generate breakdown reports from an input RProf-Rep report.
  visualize     Generate a HTML Report Viewer to see the profiling report into a web-view and a timeline.
  inspect       Inspect an application and output data about kernels from the application binary.
  summarize     Summarize global information/metrics about a profiling report.

Use '$(basename $0) <command> --help' for more information about a specific command.
EOF
    exit 0
}

BIN_DIR=$(dirname $0)
LUA_DIR=$BIN_DIR/lua
export LUA_PATH="$LUA_DIR/?.lua;;"
export INSTALL_DIR="$(realpath "$BIN_DIR/..")"

# Function to check if a command exists
command_exists() {
    which "$1" >/dev/null 2>&1
}

# Determine which Lua interpreter to use
if command_exists luajit; then
    LUA_EXEC="luajit"
elif command_exists lua; then
    LUA_EXEC="lua"
else
    echo "Error: Neither LuaJIT nor Lua is installed."
    exit 1
fi

# Check if no argument is provided
if [ -z "$1" ]; then
    echo "Error: No argument provided."
    display_help
fi

CMD="$1"
shift

args="$CMD"
for arg in "$@"; do
    args="$args '$arg'"
done

case "$CMD" in
    --help|-h)
        display_help
        ;;

    profile|stats|analyze|visualize|inspect|export|summarize|breakdown)
        eval "$LUA_EXEC $LUA_DIR/main.lua $args"
        exit_code=$?
        exit $exit_code
        ;;

    *)
        echo "Error: Invalid command '$CMD'."
        display_help
        ;;
esac



