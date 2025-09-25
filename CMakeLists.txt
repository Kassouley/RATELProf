# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

# Minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# RATELProf 
PROJECT("RATELProf" VERSION 1.0.0)

# INCLUDE(cmake/check_available_functions.cmake)
INCLUDE(cmake/check_mpi_symbols.cmake)
INCLUDE(cmake/check_rocm_symbols.cmake)

# Set output directories for all binaries and libraries
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

SET(CORE_PROJECT_NAME       "ratelprof_core"    CACHE STRING "RATELProf for the core part")
SET(EXT_PROJECT_NAME        "ratelprof_ext"     CACHE STRING "RATELProf for the extension part")
SET(WRAPPER_PROJECT_NAME    "ratelprof_wrapper" CACHE STRING "RATELProf for the wrapper part")
SET(TOOL_PROJECT_NAME       "ratelprof"         CACHE STRING "RATELProf for the tool part")

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/tools)

ADD_COMPILE_OPTIONS(
        -O3
        -D__HIP_PLATFORM_AMD__
        -Wall)

# Set the main compiler
# SET(CMAKE_C_COMPILER    /usr/bin/gcc CACHE STRING "compiler for C"   FORCE)
# SET(CMAKE_CXX_COMPILER  /usr/bin/g++ CACHE STRING "compiler for C++" FORCE)

CHECK_ROCM_SYMBOLS()
CHECK_MPI_SYMBOLS()

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
SET(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME})

INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/modules/                DESTINATION ${INSTALL_DIR}/share/modules)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/visualize/              DESTINATION ${INSTALL_DIR}/share/visualize)
INSTALL(DIRECTORY   ${CMAKE_BINARY_DIR}/lib/                          DESTINATION ${INSTALL_DIR}/lib)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/bin/ratelprof.sh RENAME "ratelprof" DESTINATION ${INSTALL_DIR}/bin 
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/lua/                      DESTINATION ${INSTALL_DIR}/bin/lua)
