#include <iostream>
#include <cstdint>
#include <string>

#include "FileIO.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <mesh_file>" << std::endl;
        return 1;
    }

    std::string f = argv[1];
    FileIO FileIO(f);
    int ierr = FileIO.getIerr();
    if (ierr != 0)
    {
        return 1;
    }
    Mesh mesh = FileIO.getMesh();
    uint64_t eid = 0;
    Element e = mesh.getMeshElementFromID(eid);
    std::cout << e.getElementNumNodes() << std::endl;
    return 0;
}
