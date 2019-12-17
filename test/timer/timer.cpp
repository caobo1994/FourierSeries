#include "timercommmon.hpp"

#include "timerAmplitude.hpp"

using namespace std;

using FLOAT = double;

int main()
{
	vector<size_t> nlist = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
	timerAmplitude<FLOAT>(nlist, "timerAmplitude.csv")
}