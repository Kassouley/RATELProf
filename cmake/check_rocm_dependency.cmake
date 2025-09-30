INCLUDE(cmake/check_available_headers.cmake)
INCLUDE(cmake/check_available_functions.cmake)

# Generic ROCm dependency checker
# HEADERS            -> list of header files to check
# DEFAULT_INCLUDE    -> default include path if AUTO
function(CHECK_ROCM_DEPENDENCY DEP_NAME HEADERS DEFAULT_INCLUDE REQUIRED)
    set(INCLUDE_VAR "${DEP_NAME}_INCLUDE_DIR")
    set(${INCLUDE_VAR} "${DEFAULT_INCLUDE}" CACHE STRING "Include directory for ${DEP_NAME}")

    # Use user-specified value if it exists and is not empty
    set(INCLUDE_DIRS "${${INCLUDE_VAR}}")
    if(NOT INCLUDE_DIRS OR INCLUDE_DIRS STREQUAL "")
        set(INCLUDE_DIRS "${DEFAULT_INCLUDE}")
    endif()

    CHECK_AVAILABLE_HEADERS(${DEP_NAME} "${HEADERS}" "${INCLUDE_DIRS}" ${REQUIRED})
endfunction()




function(CHECK_HIP_DEPENDENCY)
    SET(HEADER  hip/hip_runtime.h)

	SET(CMAKE_REQUIRED_DEFINITIONS 	"-D__HIP_PLATFORM_AMD__")
    CHECK_ROCM_DEPENDENCY(
        "HIP"
        "${HEADER}"
        "/opt/rocm/include"
        FALSE
    )
    IF(HIP_FOUND)
        CHECK_AVAILABLE_FUNCTIONS(HIP "${HIP_INCLUDE_DIR}" "${HEADER}")
    ENDIF()
	UNSET(CMAKE_REQUIRED_DEFINITIONS)

    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/hip_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/hip_conf.h"
    )
endfunction()



function(CHECK_HSA_DEPENDENCY)
    SET(HEADER  hsa/hsa.h hsa/hsa_ext_amd.h)

    CHECK_ROCM_DEPENDENCY(
        "HSA"
        "${HEADER}"
        "/opt/rocm/include"
        TRUE
    )
    IF(HSA_FOUND)
        CHECK_AVAILABLE_FUNCTIONS(HSA "${HSA_INCLUDE_DIR}" "${HEADER}")
    ENDIF()

    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/hsa_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/hsa_conf.h"
    )
endfunction()



function(CHECK_OMP_ROUTINE_DEPENDENCY)
    SET(HEADER omp.h)

    CHECK_ROCM_DEPENDENCY(
        "OMP_ROUTINE"
        "${HEADER}"
        "/opt/rocm/llvm/include"
        FALSE
    )
    IF(OMP_ROUTINE_FOUND)
        CHECK_AVAILABLE_FUNCTIONS(OMP_ROUTINE "${OMP_ROUTINE_INCLUDE_DIR}" "${OMP_ROUTINE_INCLUDE_DIR}/${HEADER}")
    ENDIF()

    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/omp_routine_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/omp_routine_conf.h"
    )
endfunction()

function(CHECK_OMP_TGT_RTL_DEPENDENCY)
    SET(DEP_NAME "OMP_TGT_RTL")
    set(OMP_TGT_RTL_LIB "/opt/rocm/llvm/lib/libomptarget.rtl.amdgpu.so" CACHE STRING "Path to the omp-tgt-rtl library")

    set(FILE_TO_CHECK "${OMP_TGT_RTL_LIB}")

    # Check if the file exists
    if(EXISTS "${FILE_TO_CHECK}")
        MESSAGE(STATUS "Found library ${OMP_TGT_RTL_LIB}")
        SET(${DEP_NAME}_FOUND          TRUE            CACHE INTERNAL "Dependency found")
        SET("HAVE_${DEP_NAME}"         1               CACHE INTERNAL "Whether ${DEP_NAME} is available")
        CHECK_AVAILABLE_FUNCTIONS(OMP_TGT_RTL "NO_CHECK" "NO_CHECK")
    else()
        message(WARNING "Library ${OMP_TGT_RTL_LIB} not found'. Trace feature for ${OMP_TGT_RTL} will not be build.")
    endif()
   
    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/omp_tgt_rtl_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/omp_tgt_rtl_conf.h"
    )
endfunction()


function(CHECK_OMPT_DEPENDENCY)
    SET(HEADER omp-tools.h)

    CHECK_ROCM_DEPENDENCY(
        "OMPT"
        "${HEADER}"
        "/opt/rocm/llvm/include"
        FALSE
    )

    CONFIGURE_FILE(
        "${RATELPROF_CONFIG_DIR}/ompt_conf.h.in"
        "${RATELPROF_CONFIG_DIR}/ompt_conf.h"
    )
endfunction()

