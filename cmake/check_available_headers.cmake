
include(CheckIncludeFile)

function(CHECK_AVAILABLE_HEADERS DEP_NAME HEADERS INCLUDE_DIRS REQUIRED)
    string(TOUPPER "${DEP_NAME}" DEP_NAME)

    if(NOT DEFINED BUILD_${DEP_NAME}_TRACING OR NOT BUILD_${DEP_NAME}_TRACING)
        return()
    endif()
    
    # Default results
    SET(${DEP_NAME}_FOUND          FALSE    CACHE INTERNAL "Dependency found")
    SET(${DEP_NAME}_INCLUDE_DIR    ""       CACHE INTERNAL "Dependency include dirs")
    SET("HAVE_${DEP_NAME}"         0        CACHE INTERNAL "Whether ${DEP_NAME} is available")

    SET(CMAKE_REQUIRED_INCLUDES ${INCLUDE_DIRS})
    SET(CMAKE_REQUIRED_FLAGS "-c")

    # Check headers
    SET(HEADER_FOUND TRUE)
	foreach(H IN LISTS HEADERS)
        set(TMP "HAS_HEADER_${DEP_NAME}")
        check_include_file(${H} ${TMP})
        if(NOT ${TMP})
            SET(HEADER_FOUND FALSE)
            SET(MISSING_HEADER ${H})
            break()
        endif()
        UNSET(${TMP})
        UNSET(${TMP} CACHE)
    endforeach()

    unset(CMAKE_REQUIRED_INCLUDES)

    if(HEADER_FOUND)
        message(STATUS "Found header ${HEADERS} in ${INCLUDE_DIRS}")
        SET(${DEP_NAME}_FOUND          TRUE            CACHE INTERNAL "Dependency found")
        SET(${DEP_NAME}_INCLUDE_DIR    ${INCLUDE_DIRS} CACHE INTERNAL "Dependency include dirs")
        SET("HAVE_${DEP_NAME}"         1               CACHE INTERNAL "Whether ${DEP_NAME} is available")
    elseif(REQUIRED)
        message(WARNING "Header ${MISSING_HEADER} not found in '${INCLUDE_DIRS}' but required, skipping ${PROJECT_NAME} build...")
    else()
        message(WARNING "Header ${MISSING_HEADER} not found in '${INCLUDE_DIRS}'. Trace feature for ${DEP_NAME} will not be build.")
    endif()
    UNSET(HEADER_FOUND)
endfunction()
