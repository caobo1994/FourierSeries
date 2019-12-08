/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_TRANSFORMTO_H
#define FSL_TRANSFORMTO_H

#include "CFSData.hpp"
#include "Integration.hpp"
#include <cmath>

/*Other library inclusion is here*/
namespace FSL{
template<class FLOAT, class FUNC>
CFST<FLOAT> TransformTo(FUNC f, size_t n, FLOAT omega)
{
    static FLOAT pi = M_PI;
    if (omega<=0)
    {
    	throw(std::invalid_argument("ConvertTo: omega<=0"));
    }
    CFST<FLOAT> res(n, omega);
    res.setAi((omega/(2*pi))Integral(f, -pi/omega, pi/omega));
    for (size_t i = 1; i <= n; ++i)
    {
    	res.setAi((omega/pi)Integral([f, i, omega](FLOAT t){return f(t)*cos(i*omega*t);}, -pi/omega, pi/omega));
    	res.setBi((omega/pi)Integral([f, i, omega](FLOAT t){return f(t)*sin(i*omega*t);}, -pi/omega, pi/omega));
    }
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */