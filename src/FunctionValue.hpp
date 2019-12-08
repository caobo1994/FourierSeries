/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_FUNCTIONVALUE_HPP
#define FSL_FUNCTIONVALUE_HPP

#include "CFSData.hpp"
#include <cmath>

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
FLOAT FUNC(const CFSData& CFS, FLOAT t)
{
    FLOAT result = 0;
    result += CFS.getAi(0);
    size_t n = CFS.getn();
    FLOAT omega = CFS.getomega()
    for (size_t i = 1; i <= n; ++i)
    {
        result += CFS.getAi(i)*cos(i*omega*t);
        result += CFS.getBi(i)*sin(i*omega*t);
    }
    return result;
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */