#ifndef FSL_CFSDATA_H
#define FSL_CFSDATA_H

#include <vector>
#include <exception>
namespace FSL{
template <class FLOAT>
class CFST
{
    using std::vector;
    private:
        size_t n;
        FLOAT omega;
        vector<FLOAT> A;
        vector<FLOAT> B;
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
        }

        const FLOAT& getomega()
        {
            return omega;
        }
        void setomega(const size_t& omega_in)
        {
            if(omega_in<=0)
            {
                throw(std::invalid_argument("setomega: omega<=0"));
            }
            omega = omega_in;
        }

        const std::vector<FLOAT>& getA()
        {
            return A;
        }
        void setA(const std::vector<FLOAT>& A_in)
        {
            if (A_in.size()!=(n+1))
            {
                throw(std::invalid_argument("setA: mismatch A.size() and n+1"));
            }
            A = A_in;
        }

        const std::vector<FLOAT>& getB()
        {
            return B;
        }
        void setB(const std::vector<FLOAT>& B_in)
        {
            if (B_in.size()!=(n))
            {
                throw(std::invalid_argument("setB: mismatch B.size() and n+1"));
            }
            B = B_in;
        }

        const FLOAT& getAi(size_t i)
        {
            if(i<0)
            {
                return std::out_of_range("getAi: i<0");
            }
            if(i>n)
            {
                return std::out_of_range("getAi: i>n");
            }
            return A[i];
        }
        void setA(size_t i, const FLOAT& Ai_in)
        {
            if(i<0)
            {
                return std::out_of_range("getAi: i<0");
            }
            if(i>n)
            {
                return std::out_of_range("getAi: i>n");
            }
            A[i] = Ai_in;
        }
        const FLOAT& getBi()
        {
            if(i<1)
            {
                return std::out_of_range("getBi: i<1");
            }
            if(i>n)
            {
                return std::out_of_range("getBi: i>n");
            }
            return B[i-1];
        }
        void setBi(const FLOAT& Bi_in)
        {            
            if(i<1)
            {
                return std::out_of_range("getBi: i<1");
            }
            if(i>n)
            {
                return std::out_of_range("getBi: i>n");
            }
            B[i-1]=Bi_in;
        }
        CFST(size_t n_in, FLOAT omega_in)
        {
            setn(n_in);
            setomega(omega_in);
        }
}
}
#endif