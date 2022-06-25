cmake_minimum_required(VERSION 3.21)
project(liszt_cxx)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(util)
list(APPEND EXTRA_LIBS ArrayUtils)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/util")

add_executable(MoveZeros MoveZeros.cpp)

target_link_libraries(MoveZeros PUBLIC ${EXTRA_LIBS} ArrayUtils)
target_include_directories(MoveZeros PUBLIC ${EXTRA_INCLUDES})

