#include "timercommon.hpp"

#include "timerAmplitude.hpp"
#include "timerMultiplication.hpp"
#include "timerTransformTo.hpp"

using namespace std;

using FLOAT = double;

int main()
{
	vector<size_t> nlist;
	size_t multi = 100;
	for (size_t i = 1; i <= 10; i++)
	{
		nlist.push_back(i*multi);
	}
	auto gen = std::mt19937_64();
	auto normal = std::normal_distribution<FLOAT>();
	auto rand = [&](){return normal(gen);};


	timerAmplitude<FLOAT>(nlist, "timerAmplitude.csv", rand);
	timerMultiplication<FLOAT>(nlist, "timerMultiplication.csv", rand);
	timerTransformTo<FLOAT>(nlist, "timerTransformTo.csv", rand);
}