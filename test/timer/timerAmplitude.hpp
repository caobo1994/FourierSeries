#pragma once

#include "Amplitude.hpp"

template <class FLOAT, class RAND>
void timerAmplitude(const std::vector<size_t>& nlist, 
	const std::string& filename, 
	RAND& rand)
{
	std::ofstream out(filename);
	for (auto n: nlist)
	{
		auto op1 = genRandCFS<FLOAT>(n, 1, rand);
		auto c = [&](){return FSL::Amplitude<FLOAT>(op1);};
		auto exectime = timer_nano(c);
		out<<n<<","<<exectime<<std::endl;
	}
	out.close();
}