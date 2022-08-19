#include "Hexahedron.h"

void Hexahedron::generateAtoIJK(uint64_t p)
{
    AtoIJK.resize(p*p*p);
    uint64_t i, j, k, c;
    c = 0;
    for (uint64_t  k = 0; k < p; i++)
    {
        for (uint64_t i = 0; i < p; i++)
        {
            for (uint64_t j = 0; j < p; j++)
            {
                AtoIJK[c] = i + j*p + k*p*p;
                c++;
            }
        }
    }
}


void Hexahedron::hexOpenRule(uint64_t p)
{
    std::vector<double> xi1d;
    std::vector<double> w1d;
    if (p == 1)
    {
        xi1d.push_back(0.0);
        w1d.push_back(2.0);
    }
    else if (p == 2)
    {
        xi1d.push_back(-1.0/sqrt(3.0));
        xi1d.push_back(1.0/sqrt(3.0));
        w1d.push_back(1.0);
        w1d.push_back(1.0);
    }
    else if (p == 3)
    {
        xi1d.push_back(-sqrt(3.0/5.0));
        xi1d.push_back(0.0);
        xi1d.push_back(sqrt(3.0/5.0));
        w1d.push_back(5.0/9.0);
        w1d.push_back(8.0/9.0);
        w1d.push_back(5.0/9.0);
    }
}