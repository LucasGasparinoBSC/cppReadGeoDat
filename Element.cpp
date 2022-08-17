#include "Element.h"

Element::Element(uint64_t n, std::vector<Point> p)
{
    elementID = n;
    elementNodes = p;
    elementNumNodes = elementNodes.size();
    elementType = (10*elementNumNodes)+elementNodes[0].getNodeDims();
}

Element::~Element()
{
    elementNodes.clear();
}

uint64_t Element::getElementID()
{
    return elementID;
}

uint64_t Element::getElementNumNodes()
{
    return elementNumNodes;
}

uint64_t Element::getElementType()
{
    return elementType;
}

std::vector<Point> Element::getElementNodes()
{
    return elementNodes;
}