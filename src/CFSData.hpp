#ifndef FSL_CFSDATA_H
#define FSL_CFSDATA_H

#include <vector>
#include <exception>
#include <string>

namespace FSL{
template <class FLOAT>
class CFST
{
    using seq=std::vector<FLOAT>;
    private:
        size_t n;
        FLOAT omega;
        seq A;
        seq B;
        //static const FLOAT zero=0;
    public:

        const size_t& getn() const
        {
            return n;
        }
        void setn(const size_t& n_in)
        {
            n = n_in;
            A.resize(n+1);
            B.resize(n);
            std::fill(A.begin(), A.end(), 0.0);
            std::fill(B.begin(), B.end(), 0.0);
        }

        const FLOAT& getomega() const
        {
            return omega;
        }
        void setomega(const FLOAT& omega_in)
        {
            if(omega_in<=0)
            {
                throw(std::invalid_argument("setomega: omega<=0"));
            }
            omega = omega_in;
        }

        const seq& getA() const
        {
            return A;
        }
        void setA(const seq& A_in)
        {
            if (A_in.size()!=(n+1))
            {
                throw(std::invalid_argument("setA: mismatch A.size() and n+1"));
            }
            A = A_in;
        }

        const seq& getB() const
        {
            return B;
        }
        void setB(const seq& B_in)
        {
            if (B_in.size()!=(n))
            {
                throw(std::invalid_argument("setB: mismatch B.size() and n"));
            }
            B = B_in;
        }

        FLOAT getAi(size_t i) const
        {
            if(i<0)
            {
                throw std::out_of_range("getAi: i<0, i=" + std::to_string(i));
            }
            if(i>n)
            {
                throw std::out_of_range("getAi: i>n, i=" + std::to_string(i) + ",n="+std::to_string(n));
            }
            return A[i];
        }
        void setAi(size_t i, const FLOAT& Ai_in)
        {
            if(i<0)
            {
                throw std::out_of_range("setAi: i<0, i=" + std::to_string(i));
            }
            if(i>n)
            {
                throw std::out_of_range("setAi: i>n, i=" + std::to_string(i) + ",n="+std::to_string(n));
            }
            A[i] = Ai_in;
        }
        FLOAT getBi(size_t i) const
        {
            if(i<0)
            {
                throw std::out_of_range("getBi: i<0, i=" + std::to_string(i));
            }
            if(i>n)
            {
                throw std::out_of_range("getBi: i>n, i=" + std::to_string(i) + ",n="+std::to_string(n));
            }
            if (i==0)
                return FLOAT(0);
            return B[i-1];
        }
        void setBi(size_t i, const FLOAT& Bi_in)
        {            
            if(i<0)
            {
                throw std::out_of_range("setBi: i<0, i=" + std::to_string(i));
            }
            if(i>n)
            {
                throw std::out_of_range("setBi: i>n, i=" + std::to_string(i) + ",n="+std::to_string(n));
            }
            if (i!=0)
                B[i-1]=Bi_in;
        }
        CFST(size_t n_in, FLOAT omega_in)
        {
            setn(n_in);
            setomega(omega_in);
        }
        CFST(size_t n_in, FLOAT omega_in, const std::vector<FLOAT>& A_in, const std::vector<FLOAT>& B_in)
        {
            setn(n_in);
            setomega(omega_in);
            setA(A_in);
            setB(B_in);
        }
};
}
#endif