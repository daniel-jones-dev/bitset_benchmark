cmake_minimum_required(VERSION 3.15)
project(bitset_benchmark)

set(CMAKE_CXX_STANDARD 11)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(google-benchmark-1.5.0)

add_executable(bitset_benchmark main.cpp helper.cpp helper.h)
target_link_libraries(bitset_benchmark benchmark benchmark_main)