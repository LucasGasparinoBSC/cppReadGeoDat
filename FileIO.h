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
        std::ifstream file;
        std::string fileName;
    public:
        FileIO(std::string s, Mesh m);
        ~FileIO();
        void openGeoDat(std::string s);
        void readGeoDat(Mesh m);
        int getIerr();
};

#endif // !FILEIO_H