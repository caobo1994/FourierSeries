/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_FUNC_HPP
#define FSL_FUNC_HPP

#include "CFSData.hpp"
#include <functional>

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT, class FUNC>
CFST<FLOAT> Function(const CFST<FLOAT>& f, const FUNC& Deriv)
{
    /*
	 * In the i-th loop:
	 * 	pf is f^i/(i!);
	 *	res is the result until now.
	 *	dd is DD(i);
	 * 	mul is 1/i	
     */
    CFST<FLOAT> pf(f.getn(), f.getomega()); 
    CFST<FLOAT> res(f.getn(), f.getomega());
    CFST<FLOAT> mul(f.getn(), f.getomega());
    CFST<FLOAT> dd(f.getn(), f.getomega());
    pf.setAi(0, 1);
    size_t n = f.getn();
    for (size_t i = 0; i <= n; ++i)
    {
    	dd.setAi(0, Deriv(i));
    	res = Addition(res, Multiplication(pf, dd));
    	pf = Multiplication(pf, f);
    	mul.setAi(0, 1/FLOAT(i+1));
    	pf = Multiplication(pf, mul);
    }
    return res;
}

template <class FLOAT>
FLOAT sinDeriv(size_t i)
{
	switch (i%4)
	{
		case 0: return 0.0;
		case 1: return 1.0;
		case 2: return 0.0;
		case 3: return -1.0;
	}
}

template <class FLOAT>
FLOAT cosDeriv(size_t i)
{
	switch (i%4)
	{
		case 0: return 1.0;
		case 1: return 0.0;
		case 2: return -1.0;
		case 3: return 0.0;
	}
}

template <class FLOAT>
FLOAT expDeriv(size_t i)
{
	return 1.0;
}

template <class FLOAT>
FLOAT lnDeriv(size_t i)
{
	if (i==0)
	{
		return 0;
	}
	FLOAT res = 1;
	for (int j = 1; j <= i; ++j)
	{
		res *= FLOAT(-j);
	}
	return res; 
}

}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */