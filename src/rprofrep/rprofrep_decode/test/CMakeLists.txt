cmake_minimum_required(VERSION 3.16)

project(readrprofrep C)

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.c")

target_link_libraries(${PROJECT_NAME} PRIVATE rprofrep_decoder)



