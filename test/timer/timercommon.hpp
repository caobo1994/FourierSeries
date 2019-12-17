#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std::chrono;

using time = std::uint64_t;

template <class FLOAT, class RAND>
CFST<FLOAT> genRandCFS(size_t n, FLOAT omega, RAND& rand)
{
	CFST<FLOAT> res(n, omega);
	for(size_t i = 0; i <= omega; ++i)
	{
		res.setAi(i, rand());
		res.setBi(i, rand());
	}
	return res;
}

template <class FUNC>
time timer_nano(FUNC func);
{

    auto t1 = std::chrono::high_resolution_clock::now();
    func();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    return duration;
}
