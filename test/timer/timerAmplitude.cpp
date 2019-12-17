#include "timerAmplitude.hpp"
template <class FLOAT>
void timerAmplitude(const std::vector<size_t>& nlist, const string& filename)
{
	std::ostream out(filename);
	for (n: nlist)
	{
		CFS<FLOAT> op1;
		auto c = [op1](){return Amplitude<FLOAT>(op1)};
		auto exectime = timer_nano(c);
		out<<n<<","<<exectime<<endl;
	}
}