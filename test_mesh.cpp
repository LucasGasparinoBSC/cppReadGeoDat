#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#include "Point.h"
#include "Element.h"
#include "Mesh.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <mesh_file>" << std::endl;
        return 1;
    }

    // Read argument into fileName string and appennd extension
    std::string fileName = argv[1];
    fileName.append(".geo.dat");
    return 0;
}
