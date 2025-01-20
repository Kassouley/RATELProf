# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 
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
    echo -e "  -h, --help \t\t\t Display this help message"
    echo -e "  -f, --filter FILE \t\t\t Specify the input file with functions to intercept"
    echo -e "  --plugin PATH \t\t\t Specify the plugin path (options: stdout or custom path)"
	echo -e "  --omp_tgt-prof 			 Enable profile of OMP_TGT library functions"
	echo -e "  --hsa-prof 			 Enable profile of HSA library functions"
	echo -e "  --omp_tgt_rtl-prof 			 Enable profile of OMP_TGT_RTL library functions"
	echo -e "  --hip-prof 			 Enable profile of HIP library functions" 
    exit 0
}

# Variables to store script options
filter_file=""
omp_tgt_prof_enabled=0
hsa_prof_enabled=0
omp_tgt_rtl_prof_enabled=0
hip_prof_enabled=0 
app_args=()
INSTALL_DIR="./build/lib"
preload_lib="$INSTALL_DIR/libratelprof.so"
plugin_path="$INSTALL_DIR/libplugin_stdout.so"

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
        --plugin)
            shift
            case $1 in
                stdout)
                    plugin_path="$INSTALL_DIR/libplugin_stdout.so"
                    ;;
                *)
                    plugin_path="$1"
                    ;;
            esac
            ;;
		--omp_tgt-prof)
			omp_tgt_prof_enabled=1
			;;
		--hsa-prof)
			hsa_prof_enabled=1
			;;
		--omp_tgt_rtl-prof)
			omp_tgt_rtl_prof_enabled=1
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
if [ $omp_tgt_prof_enabled -eq 1 ]; then
	export RATELPROF_DOMAIN_OMP_TGT=1
fi
if [ $hsa_prof_enabled -eq 1 ]; then
	export RATELPROF_DOMAIN_HSA=1
fi
if [ $omp_tgt_rtl_prof_enabled -eq 1 ]; then
	export RATELPROF_DOMAIN_OMP_TGT_RTL=1
fi
if [ $hip_prof_enabled -eq 1 ]; then
	export RATELPROF_DOMAIN_HIP=1
fi 

export RATELPROF_PLUGIN_PATH="$plugin_path"

# Preload the library and launch the application
LD_PRELOAD=$preload_lib "${app_args[@]}"
