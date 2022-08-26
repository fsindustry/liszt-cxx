cmake_minimum_required(VERSION 3.15)
project(liszt_cxx)

set(CMAKE_CXX_STANDARD 11)

# add util liberaries and includes here
add_subdirectory(util)
list(APPEND EXTRA_LIBS ArrayUtils)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/util")

# test executable binary
add_executable(hello priority_queue/_347/TopKFrequentElements.cpp priority_queue/_23/MergeKSortedLists.cpp)
target_link_libraries(hello PUBLIC ${EXTRA_LIBS})
target_link_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/util)