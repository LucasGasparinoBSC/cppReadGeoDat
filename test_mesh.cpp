#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

#include "Point.h"
#include "Element.h"
#include "Mesh.h"

int main(int argc, char const *argv[])
{
    // Check for corrrect number of arguments
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <mesh_file>" << std::endl;
        return 1;
    }

    // Instantiate a mmeshh object
    Mesh mesh;

    // Read argument into fileName string and appennd extension
    std::string fileName = argv[1];
    fileName.append(".geo.dat");

    // Open file for reading
    std::ifstream file(fileName); // Creates an input file stream and opens it
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
    }

    // Create an auxiliary line object
    std::string line;

    // Deterrmine position of each file section
    std::streampos start, end, current;
    std::streampos NPE, ELE, COO, BOU;

    start = file.tellg();
    file.seekg(0, std::ios::end);
    end = file.tellg();
    file.seekg(start);

    /*
     *
     * Read file and determine position of each section
     * Breaks loop if BOUNDARIES is found as it is the last section
     * in the file sequence.
     *
     */
    while (!file.eof())
    {
        std::getline(file, line);
        /// Nodes per element section
        if (line == "NODES_PER_ELEMENT")
        {
            NPE = file.tellg();
        }
        // Elements section
        else if (line == "ELEMENTS")
        {
            ELE = file.tellg();
        }
        // Coordinates section
        else if (line == "COORDINATES")
        {
            COO = file.tellg();
        }
        // boundaries section
        else if (line == "BOUNDARIES")
        {
            BOU = file.tellg();
            break;
        }
    }

    // Create mesh points from the Coordinate section
    file.seekg(COO);

    /*
     * Reads untill the END_COORDINATES is found. Add each point
     * to the vector of points.
     */
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
            // Read first entry into id
            ss >> id;
            // Read second and third entries into auxXYZ
            while(ss >> auxX)
            {
                auxXYZ.push_back(auxX);
            }
            // Create a point from the read data and add it to the vector of points
            /*
             * The point constructor takes an id and a vector of doubles.
             * Subtract 1 from the id to make it zero-based.
             */
            mesh.buildNodesList(id-1, auxXYZ);
        }
    }

    // Create elements from the Elements section
    /*
     * Use the list of points created previouusly, in combinnation
     * with the element tabble, to sort out the elements.
     */
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
            auxPoints.push_back(mesh.getMeshNodeFromID(pID-1));
        }
        mesh.buildElementsList(eID-1, auxPoints);
    }

    file.close();
    return 0;
}
