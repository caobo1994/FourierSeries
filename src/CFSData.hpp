#ifndef FSL_CFSDATA_H
#define FSL_CFSDATA_H

#include <vector>
#include <exception>

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

        const size_t& getn()
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

        const FLOAT& getomega()
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

        const seq& getA()
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

        const seq& getB()
        {
            return B;
        }
        void setB(const seq& B_in)
        {
            if (B_in.size()!=(n))
            {
                throw(std::invalid_argument("setB: mismatch B.size() and n+1"));
            }
            B = B_in;
        }

        FLOAT getAi(size_t i)
        {
            if(i<0)
            {
                throw std::out_of_range("getAi: i<0");
            }
            if(i>n)
            {
                throw std::out_of_range("getAi: i>n");
            }
            return A[i];
        }
        void setAi(size_t i, const FLOAT& Ai_in)
        {
            if(i<0)
            {
                throw std::out_of_range("getAi: i<0");
            }
            if(i>n)
            {
                throw std::out_of_range("getAi: i>n");
            }
            A[i] = Ai_in;
        }
        FLOAT getBi(size_t i)
        {
            if(i<0)
            {
                throw std::out_of_range("getBi: i<0");
            }
            if(i>n)
            {
                throw std::out_of_range("getBi: i>n");
            }
            if (i==0)
                return FLOAT(0);
            return B[i-1];
        }
        void setBi(size_t i, const FLOAT& Bi_in)
        {            
            if(i<0)
            {
                throw std::out_of_range("getBi: i<0");
            }
            if(i>n)
            {
                throw std::out_of_range("getBi: i>n");
            }
            if (i!=0)
                B[i-1]=Bi_in;
        }
        CFST(size_t n_in, FLOAT omega_in)
        {
            setn(n_in);
            setomega(omega_in);
        }
};
}
#endif