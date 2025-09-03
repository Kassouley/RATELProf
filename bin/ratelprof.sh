#!/bin/bash

# Function to display help message
function display_help() {
    cat << EOF
Usage: $0 [--help] <command> [options] [command args] 

Commands:
  profile       Run an application and capture its profile into a json report file.
  stats         Generate statistics from an existing json report file.
  visualize     Generate a HTML Report Viewer to see the traces into a timeline.
  inspect       Inspect an application and output data about kernels from the application.

Use '$(basename $0) <command> --help' for more information about a specific command.
EOF
    exit 0
}

if [[ -z $RATELPROF_INSTALL_DIR ]]; then
    echo "Error: RATELPROF_INSTALL_DIR env var not defined"
    exit
fi

#!/bin/bash
SCRIPT_DIR=$(dirname $0)/lua
export LUA_PATH="$SCRIPT_DIR/?.lua;;"
export INSTALL_DIR=$(realpath $RATELPROF_INSTALL_DIR)

# Check if no argument is provided
if [ -z "$1" ]; then
    echo "Error: No argument provided."
    display_help
fi

cmd="$1"
shift

args=""
for arg in "$@"; do
    args="$args '$arg'"
done

# Use a case statement to check for specific strings
case "$cmd" in
    profile)
        eval "luajit $SCRIPT_DIR/profile.lua $args"
        ;;

    stats)
        eval "luajit $SCRIPT_DIR/stats.lua $args"
        ;;

    analyze)
        eval "luajit $SCRIPT_DIR/analyze.lua $args"
        ;;

    visualize)
        eval "luajit $SCRIPT_DIR/visualize.lua $args"
        ;;

    inspect)
        eval "luajit $SCRIPT_DIR/inspect.lua $args"
        ;;

    export)
        eval "luajit $SCRIPT_DIR/export.lua $args"
        ;;

    summarize)
        eval "luajit $SCRIPT_DIR/summarize.lua $args"
        ;;

    --help|-h)
        display_help
        ;;

    *)
        echo "Error: Invalid command '$1'."
        display_help
        ;;
esac


