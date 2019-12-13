/*
 * Introduction to the header template.
 * For each function FUNC, the file name shall be FUNC.hpp in src/DeemaAlomair folder.
 * Every FUNC shall be replaced with implemented function name.
 * The type of a CFS with FLOAT is CFST<FLOAT>
 * The code shall follow c++17 standard.
 * Only the c++ standard libraries are allowed.
 * C-style code is highly not recommended.
 */

#ifndef FSL_FUNC_H
#define FSL_FUNC_H

#include <vector>
#include <Eigen/Dense>
/*Other library inclusion is here*/
namespace FSL{
    template <class FLOAT>
    void LinSolve(size_t n, const std::vector<std::vector>& M, const std::vector<FLOAT>& y, std::vector<FLOAT>& x)
    {
        Eigen::Matrix<FLOAT, Dynamic, Dynamic> ME(n, n);
        for(size_t i = 0; i < n; ++i)
        {
            for(size_t j = 0; j < n; ++j)
            {
                ME(i, j) = M[i][j];
            }
        }
        Eigen::Matrix<FLOAT, Dymanic, 1> xE(n), yE(n);
        for(size_t i =0; i<n; ++i)
        {
            yE(i) = y[i];
        }
        xE = M.colPivHouseholderQr().solve(yE);
        for (size_t i=0; i< n; ++i)
        {
            x[i]=xE(i);
        }
    }
}
#endif

/*
 * Type N in MIS shall be translated to size_t in C++. 
 * This type is already introduced in CFSData.h
 */