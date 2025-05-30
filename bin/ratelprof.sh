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

# Use a case statement to check for specific strings
case "$1" in
    profile)
        shift
        eval "luajit $SCRIPT_DIR/profile.lua $@"
        ;;

    stats)
        shift
        eval "luajit $SCRIPT_DIR/stats.lua $@"
        ;;

    analyze)
        shift
        eval "luajit $SCRIPT_DIR/analyze.lua $@"
        ;;

    visualize)
        shift
        eval "luajit $SCRIPT_DIR/visualize.lua $@"
        ;;

    inspect)
        shift
        eval "luajit $SCRIPT_DIR/inspect.lua $@"
        ;;

    export)
        shift
        eval "luajit $SCRIPT_DIR/export.lua $@"
        ;;

    --help|-h)
        display_help
        ;;

    *)
        echo "Error: Invalid command '$1'."
        display_help
        ;;
esac


