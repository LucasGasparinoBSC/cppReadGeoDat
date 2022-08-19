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
uint64_t Point::getPointID()
{
    return nodeID;
}

uint64_t Point::getPointDims()
{
    return nodeDims;
}

std::vector<double> Point::getPointXYZ()
{
    return nodeXYZ;
}

// Setters

void Point::setPointID(uint64_t n)
{
    nodeID = n;
}

void Point::setPointXYZ(std::vector<double> c)
{
    nodeXYZ = c;
}