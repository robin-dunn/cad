#include <iostream>
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <STEPControl_Writer.hxx>
#include <IFSelect_ReturnStatus.hxx>

int main() {
    std::cout << "OpenCascade Minimal Test\n";
    std::cout << "========================\n\n";
    
    // Create a simple box - this is the absolute minimum to verify OpenCascade works
    std::cout << "Creating a 10x10x10 box...\n";
    BRepPrimAPI_MakeBox boxMaker(10.0, 10.0, 10.0);
    TopoDS_Shape box = boxMaker.Shape();
    std::cout << "Box created!\n\n";
    
    // Export to STEP file so you can view it
    std::cout << "Exporting to box.step...\n";
    STEPControl_Writer writer;
    IFSelect_ReturnStatus status = writer.Transfer(box, STEPControl_AsIs);
    
    if (status == IFSelect_RetDone) {
        status = writer.Write("box.step");
        if (status == IFSelect_RetDone) {
            std::cout << "Success! File saved as 'box.step'\n";
            std::cout << "Open it in FreeCAD or any CAD viewer to see your box!\n";
        } else {
            std::cerr << "Error writing STEP file\n";
            return 1;
        }
    } else {
        std::cerr << "Error transferring shape\n";
        return 1;
    }
    
    return 0;
}
