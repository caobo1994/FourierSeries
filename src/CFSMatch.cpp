/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_CFSMATCH_HPP
#define FSL_CFSMATCH_HPP

#include "CFSData.hpp"
#include <exception>

/*Other library inclusion is here*/

namespace FSL{
template<class FLOAT>
void CFSMatch(const CFST<FLOAT>& CFSf, const CFST<FLOAT>& CFSg)
{
    if (CFSf.getn()!=CFSg.getn())
    {
    	throw(std::exception("n mismatch"));
    }
    if (CFSf.getomega()!=CFSg.getomega())
    {
    	throw(std::exception("omega mismatch"));
    }
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */