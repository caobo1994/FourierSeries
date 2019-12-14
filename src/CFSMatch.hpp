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
bool CFSMatch(const CFST<FLOAT>& CFSf, const CFST<FLOAT>& CFSg)
{
    if (CFSf.getn()!=CFSg.getn())
    {
    	return false;
    }
    if (CFSf.getomega()!=CFSg.getomega())
    {
    	return false;
    }
    return true;
}

template <class FLOAT>
[[noreturn]] void CFSMatchThrow(const CFST<FLOAT>& CFSf, const CFST<FLOAT>& CFSg)
{
	if (!CFSMatch(CFSf, CFSg))
	{
		throw std::invalid_argument("CFS not match!");
	}
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */