# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

# Minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# RATELProf 
PROJECT("RATELProf" VERSION 1.0.0)

# Set output directories for all binaries and libraries
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

SET(CORE_PROJECT_NAME       "ratelprof_core"    CACHE STRING "RATELProf for the core part")
SET(EXT_PROJECT_NAME        "ratelprof_ext"     CACHE STRING "RATELProf for the extension part")
SET(WRAPPER_PROJECT_NAME    "ratelprof_wrapper" CACHE STRING "RATELProf for the wrapper part")
SET(TOOL_PROJECT_NAME       "ratelprof"         CACHE STRING "RATELProf for the tool part")

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

FIND_PACKAGE(ROCM QUIET)
IF(NOT ROCM_FOUND)
    MESSAGE(WARNING "ROCM not found. Skipping RATELProf Module.")
    RETURN()
ENDIF()

GET_FILENAME_COMPONENT(ROCM_PATH "${ROCM_DIR}/../../.." ABSOLUTE)

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/src/tools
    ${ROCM_PATH}/llvm/include/
    ${ROCM_PATH}/include
    ${ROCM_PATH}/include/hip
    ${ROCM_PATH}/include/hsa
)

ADD_COMPILE_OPTIONS(
        -O3
        -D__HIP_PLATFORM_AMD__
        -Wall)

# Set the main compiler
SET(CMAKE_C_COMPILER    /usr/bin/gcc CACHE STRING "compiler for C++" FORCE)
SET(CMAKE_CXX_COMPILER  /usr/bin/g++ CACHE STRING "compiler for C++" FORCE)

# Add subdirectory for the shared library
ADD_SUBDIRECTORY(src/wrappers)
ADD_SUBDIRECTORY(src/core)
ADD_SUBDIRECTORY(src/ext)
ADD_SUBDIRECTORY(src/tools)
ADD_SUBDIRECTORY(src/plugins)
ADD_SUBDIRECTORY(src/lua)
ADD_SUBDIRECTORY(share/ratelinfo)

# Install scripts
SET(INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME})

INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/modules/                DESTINATION ${INSTALL_DIR}/share/modules/)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/visualize/              DESTINATION ${INSTALL_DIR}/share/visualize/)
INSTALL(DIRECTORY   ${CMAKE_BINARY_DIR}/lib/                          DESTINATION ${INSTALL_DIR}/lib)
INSTALL(TARGETS     ratelinfo RUNTIME                                 DESTINATION ${INSTALL_DIR}/bin)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/bin/ratelprof.sh RENAME "ratelprof" DESTINATION ${INSTALL_DIR}/bin/ 
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/lua/                      DESTINATION ${INSTALL_DIR}/bin/lua)
