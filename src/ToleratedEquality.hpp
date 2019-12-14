/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_TOLERATEDEQUALITY_HPP
#define FSL_TOLERATEDEQUALITY_HPP

#include "CFSData.hpp"
#include "Subtraction.hpp"
#include "Amplitude.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
bool ToleratedEquality(const CFST<FLOAT>& f, const CFST<FLOAT>& g, FLOAT tol)
{
    auto diff = Subtraction(f, g);
    FLOAT amp = Amplitude(diff);
    return (amp <= tol);
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */