/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_ADDITION_HPP
#define FSL_ADDITION_HPP

#include "CFSData.hpp"
#include "CFSMatch.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
CFST<FLOAT> Addition(const CFST<FLOAT>& CFSf, const CFST<FLOAT>& CFSg)
{
	CFSMatchThrow<FLOAT>(CFSf, CFSg);
	CFST<FLOAT> CFSres(CFSf.getn(), CFSf.getomega());
	size_t n = CFSres.getn();
	//CFSres.setAi(CFSf.getAi(0)+CFSg.getAi(0), 0);
	for (size_t i = 0; i<=n; ++i)
	{
		CFSres.setAi(i, CFSf.getAi(i)+CFSg.getAi(i));
		CFSres.setBi(i, CFSf.getBi(i)+CFSg.getBi(i));
	}    
	return CFSres;
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */