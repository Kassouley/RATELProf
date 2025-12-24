cmake_minimum_required(VERSION 3.16)

project(rprofrep_decoder_lua C)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ---- Dependencies ----
if (NOT DEFINED LUA_INCLUDE_DIR)
    message(FATAL_ERROR "LUA_INCLUDE_DIR must be provided to build the ${PROJECT_NAME} module")
endif()

# ---- Source ----
set(SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/rprofrep_lua_wrapper.c"
)

# ---- Build the Lua module ----
add_library(${PROJECT_NAME} MODULE ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX "" 
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/lua 
    OUTPUT_NAME "${PROJECT_NAME}"
)

# ---- Include dirs ----
target_include_directories(${PROJECT_NAME} PRIVATE
    ${LUA_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(${PROJECT_NAME} PRIVATE rprofrep_decoder)