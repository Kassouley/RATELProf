#!/bin/bash

function export_filter_var() {
    local file="$1"
    local file_content

    if [[ ! -f "$file" ]]; then
        echo "File not found!"
        return 1
    fi

    file_content=$(cat "$file")
    file_content=$(echo "$file_content" | tr '\n' ' ')
    file_content=$(echo "$file_content" | tr -s '[:space:]' ' ')
    file_content=$(echo "$file_content" | sed 's/, \+/,/g')
    file_content=$(echo "$file_content" | sed 's/ : \+/:/g')
    file_content=$(echo "$file_content" | tr ' ' '\n')

    # For debugging, let's print the cleaned content
    while IFS=: read -r key value; do
        key_upper=$(echo "$key" | tr '[:lower:]' '[:upper:]')
        var_name="RATELPROF_DOMAIN_${key_upper}_FUNCTIONS"
        eval "export $var_name=$value"
    done <<< "$file_content"
}

# Function to display help message
function display_help() {
    echo "Usage: $0 [options] -- application [application_args]"
    echo
    echo "Options:"
    echo "  -h, --help                       Display this help message"
    echo "  -f, --filter FILE                Specify the input file with functions to intercept"
    echo "  --hsa-prof                       Enable profile of HSA library functions"
    echo "  --hip-prof                       Enable profile of HIP library functions"
    exit 0
}

# Variables to store script options
filter_file=""
hsa_prof_enabled=0

hip_prof_enabled=0

app_args=()
preload_lib="./lib/libratelprof.so"

# Parse script arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            display_help
            ;;
        -f|--filter)
            shift
            filter_file=$1
            ;;
        --hsa-prof)
            hsa_prof_enabled=1
            ;;
        --hip-prof)
            hip_prof_enabled=1
            ;;
        --)
            shift
            app_args=("$@")
            break
            ;;
        -*)
            echo "Unknown option: $1"
            display_help
            ;;
        *)
            app_args+=("$1")
            ;;
    esac
    shift
done

# Check if application arguments are provided
if [ ${#app_args[@]} -eq 0 ]; then
    echo "Error: No application specified."
    display_help
fi

# Check if preload library exists
if [ ! -f "$preload_lib" ]; then
    echo "Error: Preload library '$preload_lib' not found."
    exit 1
fi

# Handle the input file for function interception
if [ -n "$filter_file" ]; then
    export_filter_var "$filter_file"
fi

# Handle library interception
if [ $hsa_prof_enabled -eq 1 ]; then
    export RATELPROF_DOMAIN_HSA=1
fi

if [ $hip_prof_enabled -eq 1 ]; then
    export RATELPROF_DOMAIN_HIP=1
fi


# Preload the library and launch the application
LD_PRELOAD=$preload_lib "${app_args[@]}"

