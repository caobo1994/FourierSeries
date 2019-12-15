#pragma once

#include "Power.hpp"
#include ""
using namespace FSL;

SCENARIO("Power test", "[AdvancedOp]")
{
	WHEN("Given cos and 3")
	{
		CFSO x(3, 1.0, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
		size_t n = 3;
		THEN("cos^3=0.75cos+0.25cos3")
		{
			auto res = Power(x, 3);
			CFSO rstd(3, 1.0, {0.0, 0.75, 0.0, 0.25}, {0.0, 0.0, 0.0});
			CHECK(ToleratedEquality())
		}
	}
}