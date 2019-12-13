/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_DIVISION_HPP
#define FSL_DIVISION_HPP

#include "CFSData.hpp"
#include "LinSolve.hpp"

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT>
CFST<FLOAT> FUNC(const CFST<FLOAT>& f, const CFST<FLOAT>& g)
{
   	CFSMatch<FLOAT>(f, g);
   	size_t n = f.getn();
   	CFST<FLOAT> res(f.getn(), f.getomega());
    std::vector<std::vector<FLOAT>> M(2*n+1);
    for(size_t i = 0; i < 2*n+1; ++i)
    {
    	M[i].resize(2*n+1, 0.0);
    }
    std::vector<FLOAT> x(2*n+1, 0.0);
    std::vector<FLOAT> y(2*n+1, 0.0);
    for (size_t i = 0; i <= n; ++i)
    {
    	for(size_t j = 0; j <= (n-i); ++j)
    	{
    		M[i][i+j] += g.getAi(j);
    		M[i][j] += g.getAi(i+j);
    		if (j!=0)
    			M[i][n+1+i+j] += g.getBi(j);
    		if ((i+j)!=0)
    			M[i][n+1+i] += g.getBi(i+j); 
    	}
    	for(size_t j = 0; j <= i; ++j)
    	{
    		M[i][j] += g.getAi(i-j);
    		M[i][n+1+j] -= g.getBi(i-j);
    	}
    	y[i] = f.getAi(i);
    }
    for(size_t i = 1; i <= n; ++i);
    {
    	for (size_t j = 0; j <= (n-i); ++j)
    	{
    		M[n+1+i][j] += g.getBi(i+j);
    		M[n+1+i][i+j+n+1] += g.getAi(j);
    		M[n+1+i][j+n+1] += g.getAi(i+j);
    		M[n+1+i][i+j] += g.getBi(j);
    	}
		for (size_t j = 0; j <= i; ++j)
		{
			M[n+1+i][j] += g.getBi(i-j);
			M[n+1+i][n+1+j] += g.getAi(i-j);
		}
		y[n+1+i] = f.getBi(i);
    }
    LinSolve<FLOAT>(2*n+1, M, x, y); 
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */