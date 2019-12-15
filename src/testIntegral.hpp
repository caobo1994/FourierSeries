#pragma once

#include "Integral.hpp"

using namespace FSL;

SCENARIO("Integral test", "[Integration]")
{
	WHEN("A function and a boundary is given")
	{
		auto f = [](FPT x){return x;}
		a = 0.0;
		b = 1.0;
		THEN("The integration value shall match math result")
		{
			FPT res = Integral(f, a, b);
			REQUIRE(res==0.5_a);
		}
	}
}