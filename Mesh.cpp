#include "Mesh.h"

Mesh::Mesh()
{
    meshNumNodes = 0;
    meshNumElements = 0;
}

Mesh::~Mesh()
{
    meshNodes.clear();
    meshElements.clear();
}

uint64_t Mesh::getMeshNumNodes()
{
    return meshNumNodes;
}

uint64_t Mesh::getMeshNumElements()
{
    return meshNumElements;
}

Point Mesh::getMeshNodeFromID(uint64_t id)
{
    for (uint64_t i = 0; i < meshNumNodes; i++)
    {
        if (meshNodes[i].getPointID() == id)
        {
            return meshNodes[i];
        }
    }
}

Element Mesh::getMeshElementFromID(uint64_t id)
{
    for (uint64_t i = 0; i < meshNumElements; i++)
    {
        if (meshElements[i].getElementID() == id)
        {
            return meshElements[i];
        }
    }
}

std::vector<Point> Mesh::getMeshNodes()
{
    return meshNodes;
}

std::vector<Element> Mesh::getMeshElements()
{
    return meshElements;
}

void Mesh::buildNodesList(uint64_t id, std::vector<double> pXYZ)
{
    meshNodes.push_back(Point(id, pXYZ));
    meshNumNodes++;
}

void Mesh::buildElementsList(uint64_t id, std::vector<Point> p)
{
    meshElements.push_back(Element(id, p));
    meshNumElements++;
}