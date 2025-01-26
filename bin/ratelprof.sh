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
SCRIPT_DIR=$(dirname $0)/../share/scripts

# Check if no argument is provided
if [ -z "$1" ]; then
    echo "Error: No argument provided."
    display_help
fi

# Use a case statement to check for specific strings
case "$1" in
    profile)
        shift
        eval "lua $SCRIPT_DIR/profile_command/profile.lua $@"
        ;;

    stats)
        shift
        eval "lua $SCRIPT_DIR/stats_command/stats.lua $@"
        ;;

    visualize)
        shift
        eval "lua $SCRIPT_DIR/visualize_command/visualize.lua $@"
        ;;

    inspect)
        shift
        eval "lua $SCRIPT_DIR/inspect_command/inspect.lua $@"
        ;;

    --help|-h)
        display_help
        ;;

    *)
        echo "Error: Invalid command '$1'."
        display_help
        ;;
esac


