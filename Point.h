#ifndef POINT_H
#define POINT_H

#include <vector>
#include <cstdint>

class Point
{
    private:
        uint64_t nodeID;
        uint64_t nodeDims;
        std::vector<double> nodeXYZ;
    public:
        // Constructor
        Point(uint64_t n, std::vector<double> c);
        // Destructor
        ~Point();
        // Getters
        uint64_t getNodeID();
        uint64_t getNodeDims();
        std::vector<double> getNodeXYZ();
        // Setters
        void setNodeID(uint64_t n);
        void setNodeXYZ(std::vector<double> c);
};

#endif // !POINT_H