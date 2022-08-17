#ifndef ELEMENT_H
#define ELEMENT_H


#include <vector>
#include <cstdint>
#include "Point.h"

class Element
{
    private:
        uint64_t elementID;
        uint64_t elementNumNodes;
        uint64_t elementType;
        std::vector<Point> elementNodes;
    public:
        // Constructor
        Element(uint64_t n, std::vector<Point> p);
        // Destructor
        ~Element();
        // Getters
        uint64_t getElementID();
        uint64_t getElementNumNodes();
        uint64_t getElementType();
        std::vector<Point> getElementNodes();
};

#endif