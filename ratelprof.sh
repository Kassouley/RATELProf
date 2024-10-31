#!/bin/bash

# Function to export filtered variables from the input file
function export_filter_var() {
    local file="$1"
    
    if [[ ! -f "$file" ]]; then
        echo "Error: File '$file' not found!"
        return 1
    fi

    local file_content=$(tr '\n' ' ' < "$file" | tr -s '[:space:]' ' ' | sed -e 's/, \+/,/g' -e 's/ : \+/:/g' | tr ' ' '\n')

    while IFS=: read -r key value; do
        local key_upper=$(echo "$key" | tr '[:lower:]' '[:upper:]')
        local var_name="RATELPROF_DOMAIN_${key_upper}_FUNCTIONS"
        eval "export $var_name=$value"
    done <<< "$file_content"
}

# Function to display help message
function display_help() {
    cat << EOF
Usage: $0 [options] -- application [application_args]

Options:
  -h, --help                       Display this help message
  -f, --filter FILE                Specify the input file with functions to intercept
  --plugin PATH                    Specify the plugin path for RATELProf (options: stdout, json, or custom path)
  --hsa-trace                       Enable profiling of HSA library functions
  --hip-trace                       Enable profiling of HIP library functions
  --omp-tgt-rtl-trace               Enable profiling of OMP_TGT_RTL library functions
EOF
    exit 0
}

# Function to check if the preload library exists
function check_preload_lib() {
    local preload_lib="$1"
    if [[ ! -f "$preload_lib" ]]; then
        echo "Error: Preload library '$preload_lib' not found."
        exit 1
    fi
}

# Function to parse and handle script arguments
function parse_arguments() {
    while [[ $# -gt 0 ]]; do
        case $1 in
            -h|--help)
                display_help
                ;;
            --plugin)
                shift
                case $1 in
                    stdout)
                        plugin_path="/home/lneto/RATELProf/ratelprof/build/lib/libplugin_stdout.so"
                        ;;
                    json)
                        plugin_path="/home/lneto/RATELProf/ratelprof/build/lib/libplugin_json.so"
                        ;;
                    json-dyn)
                        plugin_path="/home/lneto/RATELProf/ratelprof/build/lib/libplugin_json_dyn.so"
                        ;;
                    *)
                        plugin_path="$1"
                        ;;
                esac
                ;;
            -f|--filter)
                shift
                filter_file="$1"
                ;;
            --hsa-trace)
                hsa_prof_enabled=1
                ;;
            --hip-trace)
                hip_prof_enabled=1
                ;;
            --omp-tgt-rtl-trace)
                omp_tgt_rtl_prof_enabled=1
                ;;
            --prof-trace)
                domain_prof_enabled=1
                ;;
            --)
                shift
                app_args=("$@")
                break
                ;;
            -*)
                echo "Error: Unknown option '$1'"
                display_help
                ;;
            *)
                app_args+=("$1")
                ;;
        esac
        shift
    done
}

get_number_of_kernel() {
  local num=$(eval "nm -C -U ${app_args[0]} | grep __device_stub__ | wc -l")
  local result=32
  while [ "$result" -lt "$num" ]; do
    result=$((result * 2))
  done
  echo "$result"
}

# Main logic of the script

# Variables to store script options
filter_file=""
hsa_prof_enabled=0
hip_prof_enabled=0
omp_tgt_rtl_prof_enabled=0
domain_prof_enabled=0
plugin_path="/home/lneto/RATELProf/ratelprof/build/lib/libplugin_json.so"
app_args=()
preload_lib="/home/lneto/RATELProf/ratelprof/build/lib/libratelprof_core.so"

# Parse script arguments
parse_arguments "$@"

# Check if the application is specified
if [[ ${#app_args[@]} -eq 0 ]]; then
    echo "Error: No application specified."
    display_help
fi

# Check if preload library exists
check_preload_lib "$preload_lib"

# Handle the input file for function interception, if provided
if [[ -n "$filter_file" ]]; then
    export_filter_var "$filter_file"
fi

# Handle library interception
[[ $hsa_prof_enabled -eq 1 ]] && export RATELPROF_DOMAIN_HSA=1
[[ $hip_prof_enabled -eq 1 ]] && export RATELPROF_DOMAIN_HIP=1
[[ $omp_tgt_rtl_prof_enabled -eq 1 ]] && export RATELPROF_DOMAIN_OMP_TGT_RTL=1
[[ $domain_prof_enabled -eq 1 ]] && export RATELPROF_DOMAIN_PROFILING=1

export RATELPROF_PLUGIN_PATH="$plugin_path"
export RATELPROF_NB_KERNEL_AVAILABLE=$(get_number_of_kernel)

# Preload the library and launch the application
LD_PRELOAD="$preload_lib" "${app_args[@]}"
