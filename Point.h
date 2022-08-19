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
        uint64_t getPointID();
        uint64_t getPointDims();
        std::vector<double> getPointXYZ();
        // Setters
        void setPointID(uint64_t n);
        void setPointXYZ(std::vector<double> c);
};

#endif // !POINT_H