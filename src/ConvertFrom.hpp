/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_CONVERTFROM_HPP
#define FSL_CONVERTFROM_HPP

#include "CFSData.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
CFST<FLOAT> ConvertFrom(size_t n, FLOAT omega, const std::vector<FLOAT>& A, const std::vector<FLOAT>& B)
{
 	CFST<FLOAT> res(n, omega);
 	res.setA(A);
 	res.setB(B);
 	return res;   
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */