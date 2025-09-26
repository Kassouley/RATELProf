include(CheckIncludeFile)

# Generic ROCm dependency checker
# HEADERS            -> list of header files to check
# OPTION_INCLUDE_DIR -> user-provided include dir or "AUTO"
# DEFAULT_INCLUDE    -> default include path if AUTO
function(CHECK_ROCM_DEPENDENCY HEADERS ENV_INCLUDE_DIR DEFAULT_INCLUDE)
   if(DEFINED ENV{${ENV_INCLUDE_DIR}})
		SET(OPTION_INCLUDE_DIR "$ENV{${ENV_INCLUDE_DIR}}")
	endif()

    # Default results
    SET(_FOUND          FALSE   PARENT_SCOPE)
    SET(_INCLUDE_DIR    ""      PARENT_SCOPE)

    # Determine include dirs
    if(NOT OPTION_INCLUDE_DIR OR OPTION_INCLUDE_DIR STREQUAL "AUTO")
        SET(INCLUDE_DIRS ${DEFAULT_INCLUDE})
    else()
        SET(INCLUDE_DIRS ${OPTION_INCLUDE_DIR})
    endif()


    # Temporarily SET include dirs for checking
    SET(CMAKE_REQUIRED_INCLUDES ${INCLUDE_DIRS})

    # Check headers
    SET(HEADER_FOUND TRUE)
	foreach(H IN LISTS HEADERS)
        check_include_file(${H} HAS_HEADER)
        if(NOT HAS_HEADER)
            SET(HEADER_FOUND FALSE)
            SET(MISSING_HEADER ${H})
            break()
        endif()
        UNSET(HAS_HEADER CACHE)
        UNSET(HAS_HEADER)
    endforeach()

    unset(CMAKE_REQUIRED_INCLUDES)

    if(HEADER_FOUND)
        message(STATUS "Found header ${HEADERS} in ${INCLUDE_DIRS}")
        SET(_FOUND          TRUE            PARENT_SCOPE)
        SET(_INCLUDE_DIR    ${INCLUDE_DIRS} PARENT_SCOPE)
    else()
        message(WARNING "Header ${MISSING_HEADER} not found in ${INCLUDE_DIRS}, skipping ${PROJECT_NAME} build...")
    endif()
    UNSET(HEADER_FOUND)
    UNSET(INCLUDE_DIRS)
endfunction()

function(CHECK_HIP_DEPENDENCY)
	SET(CMAKE_REQUIRED_DEFINITIONS 	"-D__HIP_PLATFORM_AMD__")
    CHECK_ROCM_DEPENDENCY(
        "${ARGV}"
        "HIP_INCLUDE_DIR"
        "/opt/rocm/include"
    )
    SET(HIP_FOUND       ${_FOUND}       PARENT_SCOPE)
    SET(HIP_INCLUDE_DIR ${_INCLUDE_DIR} PARENT_SCOPE)
	UNSET(CMAKE_REQUIRED_DEFINITIONS)
endfunction()

function(CHECK_HSA_DEPENDENCY)
    CHECK_ROCM_DEPENDENCY(
        "${ARGV}"
        "HSA_INCLUDE_DIR"
        "/opt/rocm/include"
    )
    SET(HSA_FOUND       ${_FOUND}       PARENT_SCOPE)
    SET(HSA_INCLUDE_DIR ${_INCLUDE_DIR} PARENT_SCOPE)
endfunction()

function(CHECK_OMP_DEPENDENCY)
    CHECK_ROCM_DEPENDENCY(
        "${ARGV}"
        "OMP_INCLUDE_DIR"
        "/opt/rocm/llvm/include"
    )
    SET(OMP_FOUND       ${_FOUND}       PARENT_SCOPE)
    SET(OMP_INCLUDE_DIR ${_INCLUDE_DIR} PARENT_SCOPE)
endfunction()
