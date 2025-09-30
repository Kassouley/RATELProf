include(CheckCSourceCompiles)

function(CHECK_AVAILABLE_FUNCTIONS DEP_NAME INCLUDE_DIRS HEADERS)
    string(TOLOWER "${DEP_NAME}" DEP_NAME)
    file(STRINGS "cmake/config_functions/${DEP_NAME}_conf.txt" FUNC_LIST)

    # Build the includes block
    set(INCLUDE_CODE "")
    foreach(H IN LISTS HEADERS)
        string(APPEND INCLUDE_CODE "#include <${H}>\n")
    endforeach()

    SET(CMAKE_REQUIRED_QUIET ${CHECK_SYMBOL_QUIET})
    foreach(FUNC ${FUNC_LIST})
        if(FUNC STREQUAL "")
            continue()
        endif()
        SET(CMAKE_REQUIRED_FLAGS "-c")
        SET(CMAKE_REQUIRED_INCLUDES ${INCLUDE_DIRS})

        set(VAR_NAME "HAVE_${FUNC}")

        if(HEADERS STREQUAL "NO_CHECK")
            set(${VAR_NAME} 1 CACHE INTERNAL "Presume ${FUNC} exists")
        else()
            # Build the test source
            set(CODE "
            ${INCLUDE_CODE}
            int main(void) {
                void* ptr = (void*)(${FUNC});
                (void)ptr;
                return 0;
            }")

            check_c_source_compiles("${CODE}" ${VAR_NAME})
        endif()
    endforeach()
    SET(CMAKE_REQUIRED_QUIET OFF)
endfunction()

