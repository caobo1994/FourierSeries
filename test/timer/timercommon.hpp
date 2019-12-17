#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include "CFSData.hpp"

//using namespace std::chrono;

template <class FLOAT, class RAND>
FSL::CFST<FLOAT> genRandCFS(size_t n, FLOAT omega, RAND& rand)
{
	FSL::CFST<FLOAT> res(n, omega);
	for(size_t i = 0; i <= omega; ++i)
	{
		res.setAi(i, rand());
		res.setBi(i, rand());
	}
	return res;
}

template <class FUNC>
std::uint64_t timer_nano(FUNC func)
{

    auto t1 = std::chrono::high_resolution_clock::now();
    func();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    return duration;
}
