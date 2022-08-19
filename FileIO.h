#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>

#include "Point.h"
#include "Element.h"
#include "Mesh.h"

class FileIO
{
    private:
        int ierr = 0;
        Mesh m;
        std::ifstream file;
        std::string fileName;
        void openGeoDat(std::string s);
        void readGeoDat();
    public:
        FileIO(std::string s);
        ~FileIO();
        Mesh getMesh();
        int getIerr();
};

#endif // !FILEIO_H