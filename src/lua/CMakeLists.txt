CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(LuaModule)

MACRO(ADD_LUA_LIBRARY NAME)
    ADD_LIBRARY(${NAME} SHARED ${ARGN})
    SET_TARGET_PROPERTIES(${NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/lua
        PREFIX "")
    TARGET_INCLUDE_DIRECTORIES(${NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
ENDMACRO()

SET(MSGPACK_DIR ${CMAKE_SOURCE_DIR}/src/common/memory_structure)
FILE(GLOB MSGPACK_SRC "${MSGPACK_DIR}/msgpack*.c")

ADD_LUA_LIBRARY(msgpack_decoder msgpack/msgpack_decoder.c)
TARGET_INCLUDE_DIRECTORIES(msgpack_decoder PRIVATE ${MSGPACK_DIR})

ADD_LUA_LIBRARY(msgpack_encoder msgpack/msgpack_encoder.c ${MSGPACK_SRC})
TARGET_INCLUDE_DIRECTORIES(msgpack_encoder PRIVATE ${MSGPACK_DIR})


ADD_LUA_LIBRARY(ratelprof_agent_query ratelprof_agent_query.c)
TARGET_LINK_LIBRARIES(ratelprof_agent_query PRIVATE -lhsa-runtime64)
TARGET_LINK_DIRECTORIES(ratelprof_agent_query PRIVATE /opt/rocm/lib)


ADD_LUA_LIBRARY(demangle demangle.c)
TARGET_LINK_LIBRARIES(demangle PRIVATE -lstdc++)