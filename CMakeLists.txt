cmake_minimum_required(VERSION 3.15)
project(liszt_cxx)

set(CMAKE_CXX_STANDARD 11)

# add util liberaries and includes here
add_subdirectory(util)
list(APPEND EXTRA_LIBS ArrayUtils)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/util")

# test executable binary
add_executable(hello main.cpp array/_167/TwoSumII.cpp array/_125/ValidPalindrome.cpp array/_344/ReverseString.cpp array/_345/ReverseVowels.cpp array/_11/ContainerWithMostWater.cpp)
target_link_libraries(hello PUBLIC ${EXTRA_LIBS})
target_link_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/util)