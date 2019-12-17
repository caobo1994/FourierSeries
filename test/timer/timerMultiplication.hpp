#pragma once

#include "Multiplication.hpp"

template <class FLOAT, class RAND>
void timerMultiplication(const std::vector<size_t>& nlist, 
	const std::string& filename, 
	RAND& rand)
{
	std::ofstream out(filename);
	for (auto n: nlist)
	{
		auto op1 = genRandCFS<FLOAT>(n, 1, rand);
		auto op2 = genRandCFS<FLOAT>(n, 1, rand);
		auto c = [&](){return FSL::Multiplication<FLOAT>(op1, op2);};
		auto exectime = timer_nano(c);
		out<<n<<","<<exectime<<std::endl;
	}
	out.close();
}