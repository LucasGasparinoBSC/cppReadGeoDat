#include <iostream>
#include <vector>
#include <cstdint>

#include "Point.h"
#include "Element.h"
#include "Mesh.h"

int main(void)
{
    // Create 4 nodes
    std::vector<Point> p;
    p.push_back(Point(0, {0.0, 0.0}));
    p.push_back(Point(1, {1.0, 0.0}));
    p.push_back(Point(2, {1.0, 1.0}));
    p.push_back(Point(3, {0.0, 1.0}));

    // Create a QUA04 with the 4 nodes
    std::vector<Element> e;
    e.push_back(Element(0,p));

    // Create a grid and insert the nodes  and elements
    Mesh m;
    for (uint64_t i = 0; i < 4; i++)
    {
        m.buildNodesList(i,p[i].getNodeXYZ());
    }
    for (uint64_t i = 0; i < 1; i++)
    {
        m.buildElementsList(i,e[i].getElementNodes());
    }

    // Extract element from mesh and probe it
    Element e0 = m.getMeshElementFromID(0);
    std::cout << "--|e0 inforrmation : " << std::endl;
    std::cout << "  --|ID: " << e0.getElementID() << " " << std::endl;
    std::cout << "  --|Type: " << e0.getElementType() << " " << std::endl;
    std::cout << "  --|Nodes: " << e0.getElementNumNodes() <<std::endl;

    // Extract node 2 from mesh and probe it
    Point p2 = m.getMeshNodeFromID(2);
    std::vector<double> xyz = p2.getNodeXYZ();
    std::cout << "--|p2 inforrmation : " << std::endl;
    std::cout << "  --|ID: " << p2.getNodeID() << " " << std::endl;
    std::cout << "  --|XYZ: ";
    for (uint64_t i = 0; i < xyz.size(); i++)
    {
        std::cout << xyz[i] << " ";
    }
    std::cout<<std::endl;
    
    // End test
    return 0;
}