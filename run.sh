#!/bin/bash
cd build 2>/dev/null || mkdir build
cd build
cmake ..
make
./test
open -a FreeCAD box.step
