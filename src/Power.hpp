/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_FUNC_HPP
#define FSL_FUNC_HPP

#include "CFSData.hpp"
#include "Multiplication.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
CFST<FLOAT> Power(const CFST<FLOAT>& f, size_t n)
{
    CFST<FLOAT> res(f.getn(), f.getomega());
    for (int i = 1; i <= n; ++i)
    {
    	res = res * f;
    }
    return res;
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */