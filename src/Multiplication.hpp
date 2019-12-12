/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_MULTIPLICATION_HPP
#define FSL_MULTIPLICATION_HPP

#include "CFSData.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
CFST<FLOAT> Multiplication(const CFST<FLOAT>& f, const CFST<FLOAT>& g)
{
    CFSMatch(f, g);
   	CFST<FLOAT> CFSres(CFSf.getn(), CFSf.getomega());
	size_t n = CFSres.getn();
	for(size_t i = 0; i <=n; ++i)
	{
		FLOAT resA = 0;
		for (size_t j = 0; j <= (n-i); ++j)
		{
			resA += f.getAi(i)*g.getAi(i+j);
			resA += f.getAi(i+j)*g.getAi(i);
			resA += f.getBi(i)*g.getBi(i+j);
			resA += f.getBi(i+j)*g.getBi(i);
		}
		for (size_t j = 0; j < = i; ++j)
		{
			resA += f.getAi(j)*g.getAi(i-j)-f.getBi(j)*g.getBi(i-j);
		}
		CFSres.setAi(i, resA);
		if (i=0)
			continue;

	}
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */