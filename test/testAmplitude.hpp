#pragma once

#include "Amplitude.hpp"

using namespace FSL;

SCENARIO("Amplitude test", "[BasicOp]")
{
	WHEN("Given a CFS")
	{
		CFSO f(2, 1.0, {1.0, 2.0, 2.0}, {2.0, 2.0});
		THEN("Its amplitude shall be the same as the one computed manually");
		{
			FPT epsilon = 0.000001;
			REQUIRE(abs(Amplitude(f)-3.0)<=epsilon);
		}
	}
}