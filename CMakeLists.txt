# Minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# RATELProf 
PROJECT("RATELProf" LANGUAGES C VERSION 1.4.0)

# Set output directories for all binaries and libraries
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

SET(CORE_PROJECT_NAME       "ratelprof_core"    CACHE STRING "RATELProf for the core part")
SET(EXT_PROJECT_NAME        "ratelprof_ext"     CACHE STRING "RATELProf for the extension part")
SET(WRAPPER_PROJECT_NAME    "ratelprof_wrapper" CACHE STRING "RATELProf for the wrapper part")
SET(TOOL_PROJECT_NAME       "ratelprof"         CACHE STRING "RATELProf for the tool part")

SET(LUA_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/lua/include" CACHE PATH "Path to the Lua include directory")

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

ADD_COMPILE_OPTIONS(-O3 -Wall)

SET(LSGPU_VENDOR_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/core/include")
ADD_SUBDIRECTORY(external/lsgpu)
TARGET_COMPILE_OPTIONS(lsgpu_query PRIVATE -include ${CMAKE_CURRENT_SOURCE_DIR}/src/common/hsa_api.h)

ADD_SUBDIRECTORY(external/liborkh)

# Add subdirectory for the shared library
ADD_SUBDIRECTORY(src/core)
ADD_SUBDIRECTORY(src/ext)
ADD_SUBDIRECTORY(src/wrappers)
ADD_SUBDIRECTORY(src/tools)
# ADD_SUBDIRECTORY(src/plugins)
ADD_SUBDIRECTORY(src/lua)

ADD_SUBDIRECTORY(src/rprofrep/rprofrep_encode)
ADD_SUBDIRECTORY(src/rprofrep/rprofrep_decode)

# Install scripts
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/share/modules/                           DESTINATION ${CMAKE_INSTALL_PREFIX}/share/modules)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/external/RATELProf-Visualize/share/html/ DESTINATION ${CMAKE_INSTALL_PREFIX}/share/visualize)
INSTALL(DIRECTORY   ${CMAKE_BINARY_DIR}/lib/                                     DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
INSTALL(FILES ${CMAKE_SOURCE_DIR}/bin/ratelprof.sh RENAME "ratelprof"            DESTINATION ${CMAKE_INSTALL_PREFIX}/bin 
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
INSTALL(DIRECTORY   ${CMAKE_SOURCE_DIR}/bin/lua/                                 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/lua)
