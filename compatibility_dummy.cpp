#include <iostream>

#include "compatibility_dummy.hpp"

CompatibilityDummy::CompatibilityDummy(size_t numObjects, size_t numLabels) :
    Compatibility(numObjects, numLabels)
{
    calculate();
}

void CompatibilityDummy::calculate()
{
    if (verbose > 1)
    {
        std::cout << "About to calculate compatibility:" << std::endl;
    }

    for (size_t i = 0; i < numObjects; ++i)
    {
        int numTabs = 0;
        if (verbose > 1)
        {
            std::cout << "i = " << i << std::endl;
        }
        for (size_t j = 0; j < numLabels; ++j)
        {
            if (verbose > 1)
            {
                std::cout << "j = " << j << std::endl;
            }
            for (size_t k = 0; k < numObjects; ++k)
            {
                if (verbose > 1)
                {
                    std::cout << "k = " << k << std::endl;
                }
                for (size_t l = 0; l < numLabels; ++l)
                {
                    if (i == j && k == l)
                    {
                        compatibility(i, j, k, l) = 1.0;
                    }
                    else
                    {
                        compatibility(i, j, k, l) = -1.0;
                    }
                    if (verbose > 1)
                    {
                        std::cout << "l = " << l << std::endl;
                        std::cout << '\t' << "compatibility = " << compatibility(i, j, k, l) << std::endl;
                    }
                }
            }
        }
    }
}
