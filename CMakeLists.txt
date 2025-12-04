cmake_minimum_required(VERSION 3.14)
project(occt_minimal_test)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCASCADE REQUIRED)

include_directories(${OpenCASCADE_INCLUDE_DIR})

add_executable(test main.cpp)

target_link_libraries(test TKernel TKBRep TKPrim)
