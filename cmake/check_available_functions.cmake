include(CheckSymbolExists)
include(CheckCXXSymbolExists)

function(CHECK_AVAILABLE_FUNCTION LIB_NAME HEADER CONFIG_DIR)
    # Read the list of functions from the config file
    file(STRINGS "cmake/config_functions/${LIB_NAME}_conf.txt" FUNC_LIST)

    # set(CMAKE_REQUIRED_QUIET ON)
    SET(CMAKE_REQUIRED_FLAGS "-c")

    # Loop over each function
    foreach(FUNC ${FUNC_LIST})
        if(FUNC STREQUAL "")  # Skip empty lines
            continue()
        endif()

        set(VAR_NAME "HAVE_${FUNC}")

        if(HEADER STREQUAL "NO_CHECK")
            # Pretend all functions exist
            set(${VAR_NAME} 1 CACHE INTERNAL "Presume ${FUNC} exists")
        else()
            # Actually check for the function in the header
            check_symbol_exists(${FUNC} "${HEADER}" ${VAR_NAME})
        endif()
    endforeach()

    set(CMAKE_REQUIRED_QUIET OFF)

    # Debug message
    message(STATUS "Configuring: ${CONFIG_DIR}/${LIB_NAME}_conf.h.in")

    # Configure the header
    configure_file(
        "${CONFIG_DIR}/${LIB_NAME}_conf.h.in"
        "${CONFIG_DIR}/${LIB_NAME}_conf.h"
    )
endfunction()
