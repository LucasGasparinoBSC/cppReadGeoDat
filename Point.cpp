#include "Point.h"

// Constructor
Point::Point(uint64_t n, std::vector<double> c)
{
    nodeID = n;
    nodeDims = c.size();
    nodeXYZ.resize(nodeDims);
    nodeXYZ = c;
}

// Destructor
Point::~Point()
{
    nodeXYZ.clear();
}

// Getters
uint64_t Point::getNodeID()
{
    return nodeID;
}

uint64_t Point::getNodeDims()
{
    return nodeDims;
}

std::vector<double> Point::getNodeXYZ()
{
    return nodeXYZ;
}

// Setters

void Point::setNodeID(uint64_t n)
{
    nodeID = n;
}

void Point::setNodeXYZ(std::vector<double> c)
{
    nodeXYZ = c;
}