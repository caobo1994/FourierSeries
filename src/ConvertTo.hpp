/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_CONVERTTO_HPP
#define FSL_CONVERTTO_HPP

#include "CFSData.hpp"
#include <tuple>

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
auto ConvertTo(const CFST<FLOAT>& f)
{
    std::vector<FLOAT> A = f.getA();
    std::vector<FLOAT> B = f.getB();
    return std::make_tuple(f.getn(), f.getomega(), A, B);
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */