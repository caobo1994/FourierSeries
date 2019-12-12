/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_AMPLITUDE_HPP
#define FSL_AMPLITUDE_HPP

#include "CFSData.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
inline FLOAT sqr()
template<class FLOAT>
FLOAT Amplitude(const CFST<FLOAT>& f)
{
    FLOAT ressq = f.getAi();
    for (size_t)
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */