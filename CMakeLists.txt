# THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
# YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# RATELProf 
project("RATELProf" VERSION 1.0.0)

# Set output directories for all binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")


set(CORE_PROJECT_NAME       "ratelprof_core"    CACHE STRING "RATELProf for the core part")
set(EXT_PROJECT_NAME        "ratelprof_ext"     CACHE STRING "RATELProf for the extension part")
set(WRAPPER_PROJECT_NAME    "ratelprof_wrapper" CACHE STRING "RATELProf for the wrapper part")
set(TOOL_PROJECT_NAME       "ratelprof"         CACHE STRING "RATELProf for the tool part")

MACRO(SUBDIRLIST result curdir)
    file(GLOB_RECURSE ALL_ITEMS LIST_DIRECTORIES true ${curdir} ${curdir}/*)
    set(SUBDIRS [])
    foreach(ITEM ${ALL_ITEMS})
        if(IS_DIRECTORY ${ITEM})
            list(APPEND SUBDIRS ${ITEM})
        endif()
    endforeach()
    set(${result} ${SUBDIRS})
ENDMACRO()


# Use an environment variable for ROCm path, falling back to /opt/rocm if not set
set(ROCM_PATH $ENV{ROCM_PATH} CACHE PATH "Path to ROCm toolkit")
if (NOT ROCM_PATH)
    set(ROCM_PATH "/opt/rocm")
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/src/tools
    ${ROCM_PATH}/llvm/include/
    ${ROCM_PATH}/include
    ${ROCM_PATH}/include/hip
    ${ROCM_PATH}/include/hsa
)

# Set the main compiler
# set(CMAKE_C_COMPILER ${ROCM_PATH}/bin/hipcc)
# set(CMAKE_CXX_COMPILER ${ROCM_PATH}/bin/hipcc)
set(CMAKE_C_COMPILER /usr/bin/gcc CACHE STRING "compiler for C++" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE STRING "compiler for C++" FORCE)

# Add subdirectory for the shared library
add_subdirectory(src/wrappers)
add_subdirectory(src/core)
add_subdirectory(src/ext)
add_subdirectory(src/tools)
add_subdirectory(src/plugins)
add_subdirectory(share/ratelinfo)

# Define a list of possible targets
set(TARGETS_TO_CONFIGURE ${CORE_PROJECT_NAME} ${EXT_PROJECT_NAME})

# Apply compilation options to each existing target
foreach(TARGET_NAME IN LISTS TARGETS_TO_CONFIGURE)
    if(TARGET ${TARGET_NAME})  # Check if the target exists
        target_compile_options(${TARGET_NAME} 
            PUBLIC
                -O3
                -D__HIP_PLATFORM_AMD__
        )
        message(STATUS "Applied compile options to target: ${TARGET_NAME}")
    else()
        message(WARNING "Target ${TARGET_NAME} not found, skipping.")
    endif()
endforeach()

# Install scripts
install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/scripts/ DESTINATION ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME}/share/scripts/)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/share/visualize/ DESTINATION ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME}/share/visualize/)
install(DIRECTORY ${CMAKE_BINARY_DIR}/lib/ 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME}/lib
    FILES_MATCHING PATTERN "*.so"
)
install(TARGETS ratelinfo         RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME}/bin)
install(FILES ${CMAKE_SOURCE_DIR}/bin/ratelprof.sh 
        RENAME "ratelprof"
        DESTINATION ${CMAKE_INSTALL_PREFIX}/${TOOL_PROJECT_NAME}/bin/
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)

