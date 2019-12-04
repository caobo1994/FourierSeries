/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_INTEGRAL_H
#define FSL_INTEGRAL_H

/*Other library inclusion is here*/
#include <boost/math/quadrature/trapezoidal.hpp>
/*
template<class F, class Real>
Real trapezoidal(F f, Real a, Real b,
                 Real tol = sqrt(std::numeric_limits<Real>::epsilon()),
                 size_t max_refinements = 10,
                 Real* error_estimate = nullptr,
                 Real* L1 = nullptr);
*/

namespace FSL{
template<class FLOAT, class FUNC>
FLOAT Integral(FUNC f, FLOAT a, FLOAT b)
{
	using boost::math::quadrature::trapezoidal;
	return trapezoidal<FUNC, FLOAT>(f, a, b);
}
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */