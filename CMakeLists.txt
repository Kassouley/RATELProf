# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

# Minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# RATELProf 
PROJECT("RATELProf" VERSION 1.0.0)

INCLUDE(cmake/check_mpi_dependency.cmake)
INCLUDE(cmake/check_rocm_dependency.cmake)

# Set output directories for all binaries and libraries
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

SET(CORE_PROJECT_NAME       "ratelprof_core"    CACHE STRING "RATELProf for the core part")
SET(EXT_PROJECT_NAME        "ratelprof_ext"     CACHE STRING "RATELProf for the extension part")
SET(WRAPPER_PROJECT_NAME    "ratelprof_wrapper" CACHE STRING "RATELProf for the wrapper part")
SET(TOOL_PROJECT_NAME       "ratelprof"         CACHE STRING "RATELProf for the tool part")

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

ADD_COMPILE_OPTIONS(-O3 -D__HIP_PLATFORM_AMD__ -Wall)

SET(RATELPROF_CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/config)

option(BUILD_HIP_TRACING            "Enable HIP API tracing build"              ON)
option(BUILD_HSA_TRACING            "Enable HSA API tracing build"              ON)
option(BUILD_OMP_ROUTINE_TRACING    "Enable OMP routine tracing build"          ON)
option(BUILD_OMP_TGT_RTL_TRACING    "Enable OMP target RTL tracing build"       ON)
option(BUILD_MPI_TRACING            "Enable MPI API tracing build"              ON)
option(BUILD_OMPT_TRACING           "Enable OMPT API tracing build"             ON)

option(CHECK_SYMBOL_QUIET           "Enable quiet mode for symbols checking"    OFF)

MESSAGE(STATUS "Checking for depedency... Please wait.")
IF(CHECK_SYMBOL_QUIET)
    message(STATUS "(Quiet mode enabled for symbol checks.)")
ENDIF()

CHECK_HSA_DEPENDENCY()
IF(NOT HSA_FOUND)
    RETURN()
ENDIF()

CHECK_MPI_DEPENDENCY()
CHECK_HIP_DEPENDENCY()
CHECK_OMP_ROUTINE_DEPENDENCY()
CHECK_OMP_TGT_RTL_DEPENDENCY()
# TODO 30/07/2025 : Implement OMPT dependency checking
# CHECK_OMPT_DEPENDENCY()

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/src/config
    ${CMAKE_SOURCE_DIR}/src/tools
    ${MPI_INCLUDE_DIR}
    ${HSA_INCLUDE_DIR}
    ${HIP_INCLUDE_DIR}
    ${OMP_ROUTINE_INCLUDE_DIR}
    ${OMPT_INCLUDE_DIR}
)


# Add subdirectory for the shared library
ADD_SUBDIRECTORY(src/core)
ADD_SUBDIRECTORY(src/ext)
ADD_SUBDIRECTORY(src/tools)
ADD_SUBDIRECTORY(src/wrappers)
ADD_SUBDIRECTORY(src/plugins)
ADD_SUBDIRECTORY(src/lua)

FUNCTION(REMOVE_STATIC_BUILD TARGET_NAME)
    SET(LIB "${TARGET_NAME}-lib-static")
    IF (TARGET ${LIB})
        MESSAGE(STATUS "Removing target: ${LIB}")
        SET_TARGET_PROPERTIES(${LIB} PROPERTIES EXCLUDE_FROM_ALL TRUE)
    endif()
ENDFUNCTION()

# Remove static build (comment the following line if you want it)
# REMOVE_STATIC_BUILD(${CORE_PROJECT_NAME})
# REMOVE_STATIC_BUILD(${EXT_PROJECT_NAME})
REMOVE_STATIC_BUILD(${WRAPPER_PROJECT_NAME})
REMOVE_STATIC_BUILD(${TOOL_PROJECT_NAME})

# Install scripts
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/modules/                DESTINATION ${CMAKE_INSTALL_PREFIX}/share/modules)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/visualize/              DESTINATION ${CMAKE_INSTALL_PREFIX}/share/visualize)
INSTALL(DIRECTORY   ${CMAKE_BINARY_DIR}/lib/                          DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/bin/ratelprof.sh RENAME "ratelprof" DESTINATION ${CMAKE_INSTALL_PREFIX}/bin 
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/lua/                      DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/lua)
