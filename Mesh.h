#ifndef MESH_H
#define MESH_H

#include <vector>
#include <list>
#include <cstdint>
#include "Point.h"
#include "Element.h"

class Mesh
{
    private:
        uint64_t meshNumNodes;
        uint64_t meshNumElements;
        std::vector<Point> meshNodes;
        std::vector<Element> meshElements;
    public:
        // Constructor
        Mesh();
        // Destructor
        ~Mesh();
        // Getters
        uint64_t getMeshNumNodes();
        uint64_t getMeshNumElements();
        Point getMeshNodeFromID(uint64_t id);
        Element getMeshElementFromID(uint64_t id);
        std::vector<Point> getMeshNodes();
        std::vector<Element> getMeshElements();
        // Builders
        void buildNodesList(uint64_t id, std::vector<double> pXYZ);
        void buildElementsList(uint64_t id, std::vector<Point> p);
};

#endif