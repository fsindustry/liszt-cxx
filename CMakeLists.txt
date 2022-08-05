cmake_minimum_required(VERSION 3.15)
project(liszt_cxx)

set(CMAKE_CXX_STANDARD 11)

# add util liberaries and includes here
add_subdirectory(util)
list(APPEND EXTRA_LIBS ArrayUtils)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/util")

# test executable binary
add_executable(hello stack/_94/BinaryTreeInorderTraversal.cpp stack/_145/BinaryTreePostorderTraversal.cpp stack/_341/FlattenNestedListIterator.cpp)
target_link_libraries(hello PUBLIC ${EXTRA_LIBS})
target_link_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/util)