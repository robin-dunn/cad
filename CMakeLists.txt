cmake_minimum_required(VERSION 3.14)
project(occt_minimal_test)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCASCADE REQUIRED)

include_directories(${OpenCASCADE_INCLUDE_DIR})
link_directories(${OpenCASCADE_LIBRARY_DIR})

add_executable(test main.cpp)

# Link against OpenCASCADE libraries
# OpenCascade 7.9.2 uses TKDESTEP for STEP export (not TKSTEPBase)
target_link_libraries(test 
    TKernel      # Core kernel
    TKMath       # Math utilities
    TKBRep       # Boundary representation
    TKG3d        # 3D geometry
    TKTopAlgo    # Topological algorithms
    TKPrim       # Primitive shapes
    TKXSBase     # Exchange base
    TKDESTEP     # Data Exchange STEP (new in 7.9.2)
)