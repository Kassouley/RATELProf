#!/bin/bash

# Function to display help message
function display_help() {
    cat << EOF
Usage: $0 [--help] <command> [options] [command args] 

Commands:
  profile       Run an application and capture its profile into a json report file.
  stats         Generate statistics from an existing json report file.
  visualize     Generate a HTML Report Viewer to see the traces into a timeline

Use '$0 <command> --help' for more information about a specific command.
EOF
    exit 0
}

#!/bin/bash
INSTALL_DIR=$RATELPROF_INSTALL_DIR/share/scripts

# Check if no argument is provided
if [ -z "$1" ]; then
    echo "Error: No argument provided."
    display_help
fi

# Use a case statement to check for specific strings
case "$1" in
    profile)
        shift
        eval "lua $INSTALL_DIR/profile_command/profile.lua $@"
        ;;

    stats)
        shift
        eval "lua $INSTALL_DIR/stats_command/stats.lua $@"
        ;;

    visualize)
        shift
        echo "Work in progress"
        ;;

    --help|-h)
        display_help
        ;;

    *)
        echo "Error: Invalid command '$1'."
        display_help
        ;;
esac


