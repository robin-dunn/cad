#include <iostream>
#include <BRepPrimAPI_MakeBox.hxx>

int main() {
    std::cout << "OpenCascade Minimal Test\n";
    
    // Create a simple box - this is the absolute minimum to verify OpenCascade works
    BRepPrimAPI_MakeBox box(10.0, 10.0, 10.0);
    
    std::cout << "Success! OpenCascade is working.\n";
    
    return 0;
}
