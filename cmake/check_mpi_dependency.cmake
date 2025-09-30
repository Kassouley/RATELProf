INCLUDE(cmake/check_available_headers.cmake)
INCLUDE(cmake/check_available_functions.cmake)

function(CHECK_MPI_DEPENDENCY)
    SET(HEADER mpi.h)
	SET(DEP_NAME MPI)

    # Determine include directories
    if(NOT MPI_INCLUDE_DIR OR MPI_INCLUDE_DIR STREQUAL "AUTO")
        # Auto-detect via find_package if possible
		find_package(MPI REQUIRED)
		if(MPI_C_FOUND)
			set(MPI_INCLUDE_DIR ${MPI_C_INCLUDE_DIRS})
		endif()
    endif()

    CHECK_AVAILABLE_HEADERS(${DEP_NAME} ${HEADER} ${MPI_INCLUDE_DIR} FALSE)
    IF(MPI_FOUND)
        CHECK_AVAILABLE_FUNCTIONS(${DEP_NAME} "${MPI_INCLUDE_DIR}" "${HEADER}")
    ENDIF()

    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/mpi_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/mpi_conf.h"
    )
endfunction()

