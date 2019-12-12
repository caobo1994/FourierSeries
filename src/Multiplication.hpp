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
	/*std::vector<FLOAT> A(n+1);
	std::vector<FLOAT> B(n+1);
	for(size_t i = 0; i <= n; ++i)
	{	
		for (size_t j = 0; j <= n; ++j)
		{
			A[abs(i-j)] += 0.5 * (f.getAi(i) * g.getAi(j) + f.getBi(i) * g.getBi(j));
			B[abs(i-j)] += 0.5 * (f.getBi(i) * g.getAi(j) - f.getAi(i) * g.getBi(i));
			if ((i+j) <= n)
			{
				A[i+j] += 0.5 * (f.getAi(i) * g.getAi(j)+f.getBi(i) * g.getBi(j));
				B[i+j] += 0.5 * (f.getAi(i) * g.getBi(j)+f.getBi(i) * g.getAi(j));
			}
		}
	}
	for (size_t i = 0; i < n; ++i)
	{
		CFSres.setAi(A[i]);
		CFSres.setBi(B[i]);
	}*/
	for (size_t i = 0; i <= n; ++i)
	{
		FLOAT resA=0;
		for (size_t j = 0; j <= (n-i); ++j)
		{
			resA += f.getAi(j)*g.getAi(i+j);
			resA += g.getAi(j)*f.getAi(i+j);
			resA += f.getBi(j)*g.getBi(i+j);
			resA += g.getBi(j)*f.getBi(i+j);
		}
		for (size_t j = 0; j <= i; ++j)
		{
			resA += f.getAi(j)*g.getAi(i-j);
			resA -= f.getBi(j)*g.getBi(i-j);
		}
		CFS.setAi(0.5*resA);
	}
	for (size_t i = 1; i <= n; ++i)
	{
		FLOAT resB=0;
		for (size_t j = 0; j < (n-i); ++j)
		{
			resB += f.getAi(j)*g.getBi(i+j);
			resB += g.getAi(j)*f.getBi(i+j);
			resB += f.getBi(j)*g.getAi(i+j);
			resB += g.getBi(j)*f.getAi(i+j);			
		}
		for (size_t j = 0; j <= i; ++j)
		{
			resB += f.getAi(j)*g.getBi(i-j);
			resB += f.getBi(j)*g.getAi(i-j);
		}
		CFS.setBi(0.5*resB);
	}
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */