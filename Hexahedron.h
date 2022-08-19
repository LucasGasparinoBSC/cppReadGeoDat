#ifndef HEXAHEDRON_H
#define HEXAHEDRON_H


#include "Element.h"

class Hexahedron : public Element
{
    private:
        std::vector<uint64_t> AtoIJK;
        void generateAtoIJK(uint64_t p);
        void hexOpenRule(uint64_t p);
    public:
};

#endif