#include "FileIO.h"

FileIO::FileIO(std::string s, Mesh m)
{
    openGeoDat(s);
    readGeoDat(m);
}

FileIO::~FileIO()
{
    file.close();
}

void FileIO::openGeoDat(std::string s)
{
    fileName = s;
    fileName.append(".geo.dat");
    file.open(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        ierr = 1;
    }
}

void FileIO::readGeoDat(Mesh m)
{
    std::string line;
    std::streampos start, end, current;
    std::streampos NPE, ELE, COO, BOU;
    start = file.tellg();
    file.seekg(0, std::ios::end);
    end = file.tellg();

    file.seekg(start);
    while (!file.eof())
    {
        std::getline(file, line);
        if (line == "NODES_PER_ELEMENT")
        {
            NPE = file.tellg();
        }
        else if (line == "ELEMENTS")
        {
            ELE = file.tellg();
        }
        else if (line == "COORDINATES")
        {
            COO = file.tellg();
        }
        else if (line == "BOUNDARIES")
        {
            BOU = file.tellg();
            break;
        }
    }

    file.seekg(COO);
    while (!file.eof())
    {
        std::getline(file, line);
        if (line == "END_COORDINATES")
        {
            std::cout << "--| All points read!" << std::endl;
            break;
        }
        else
        {
            uint64_t id;
            double auxX;
            std::vector<double> auxXYZ;
            std::stringstream ss(line);
            ss >> id;
            while(ss >> auxX)
            {
                auxXYZ.push_back(auxX);
            }
            m.buildNodesList(id-1, auxXYZ);
        }
    }
    
    file.seekg(ELE);
    while (!file.eof())
    {
        std::getline(file, line);
        if (line == "END_ELEMENTS")
        {
            std::cout << "--| All elements read!" << std::endl;
            break;
        }
        uint64_t eID;
        uint64_t pID;
        std::vector<Point> auxPoints;
        std::stringstream ss(line);
        ss >> eID;
        while(ss >> pID)
        {
            auxPoints.push_back(m.getMeshNodeFromID(pID-1));
        }
        m.buildElementsList(eID-1, auxPoints);
    }
}

int FileIO::getIerr()
{
    return ierr;
}