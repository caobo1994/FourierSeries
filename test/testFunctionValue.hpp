#pragma once

#include "FunctionValue.hpp"

using namespace FSL;

SCENARIO("FunctionValue test", "[Transform]")
{
	WHEN("Given a CFS and variable value")
	{
		CFSO f(2, 1.0, {0, 2.0, 0.0}, {-2.0, 1.0});
		FPT t=M_PI/4;
		THEN("Function value shall be the std answer")
		{
			REQUIRE_THAT(FunctionValue(f, t), Catch::WithinAbs(2+sqrt(2)/2, 0.000001));
		}
	}
}
