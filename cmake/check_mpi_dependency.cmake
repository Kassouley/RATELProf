include(CheckIncludeFile)

function(CHECK_MPI_DEPENDENCY HEADER)
	set(VAR_PREFIX MPI)

    if(DEFINED ENV{MPI_INCLUDE_DIR})
        set(OPTION_INCLUDE_DIR "$ENV{MPI_INCLUDE_DIR}")
    endif()

    # Default result
    set(${VAR_PREFIX}_FOUND       FALSE PARENT_SCOPE)
    set(${VAR_PREFIX}_INCLUDE_DIR ""    PARENT_SCOPE)

    # Determine include directories
    if(NOT OPTION_INCLUDE_DIR OR OPTION_INCLUDE_DIR STREQUAL "AUTO")
        # Auto-detect via find_package if possible
		find_package(MPI REQUIRED)
		if(MPI_C_FOUND)
			set(MPI_INCLUDE_DIRS ${MPI_C_INCLUDE_DIRS})
		else()
			message(WARNING "MPI not found, skipping ${PROJECT_NAME} build...")
			return()
		endif()
    else()
        # Use user-provided include dir
        set(MPI_INCLUDE_DIRS ${OPTION_INCLUDE_DIR})
    endif()

    # Temporarily add include dir to check
    SET(CMAKE_REQUIRED_INCLUDES ${MPI_INCLUDE_DIRS})
    check_include_file(${HEADER} ${VAR_PREFIX}_HAS_HEADER)

    if(${VAR_PREFIX}_HAS_HEADER)
        message(STATUS "Found header ${HEADER} in ${MPI_INCLUDE_DIRS}")
        set(${VAR_PREFIX}_FOUND TRUE PARENT_SCOPE)
        set(${VAR_PREFIX}_INCLUDE_DIR ${MPI_INCLUDE_DIRS} PARENT_SCOPE)
    else()
        message(WARNING "Header ${HEADER} not found in ${MPI_INCLUDE_DIRS}, skipping ${PROJECT_NAME} build...")
    endif()
endfunction()

