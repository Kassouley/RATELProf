include(CheckCSourceCompiles)

function(CHECK_AVAILABLE_FUNCTION LIB_NAME HEADERS CONFIG_DIR)
    file(STRINGS "cmake/config_functions/${LIB_NAME}_conf.txt" FUNC_LIST)

    foreach(FUNC ${FUNC_LIST})
        if(FUNC STREQUAL "")
            continue()
        endif()
        SET(CMAKE_REQUIRED_FLAGS "-c")

        set(VAR_NAME "HAVE_${FUNC}")

        if(HEADERS STREQUAL "NO_CHECK")
            set(${VAR_NAME} 1 CACHE INTERNAL "Presume ${FUNC} exists")
        else()
            # Build the includes block
            set(INCLUDE_CODE "")
            foreach(H ${HEADERS})
                string(APPEND INCLUDE_CODE "#include <${H}>\n")
            endforeach()

            # Build the test source
            set(CODE "
            ${INCLUDE_CODE}
            int main(void) {
                /* If it's a function, we can take its address */
                void* ptr = (void*)(${FUNC});
                (void)ptr;
                return 0;
            }")

            check_c_source_compiles("${CODE}" ${VAR_NAME})
        endif()
    endforeach()

    configure_file(
        "${CONFIG_DIR}/${LIB_NAME}_conf.h.in"
        "${CONFIG_DIR}/${LIB_NAME}_conf.h"
    )
endfunction()

