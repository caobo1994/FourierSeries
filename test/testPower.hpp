#pragma once

#include "Power.hpp"
#include "ToleratedEquality.hpp"
using namespace FSL;

SCENARIO("Power test", "[AdvancedOp]")
{
	WHEN("Given cos and 3")
	{
		CFSO x(3, 1.0, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
		size_t n = 3;
		THEN("cos^3=0.75cos+0.25cos3")
		{
			auto res = Power(x, n);
			std::cout<<res<<endl;
			CFSO rstd(3, 1.0, {0.0, 0.75, 0.0, 0.25}, {0.0, 0.0, 0.0});
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
	WHEN("Given sin and 3")
	{
		CFSO x(3, 1.0, {0.0, 0.0, 0.0, 0.0}, {1.0, 0.0, 0.0});
		size_t n = 3;
		THEN("sin^3=0.75sin-0.25sin3")
		{
			auto res = Power(x, n);
			std::cout<<res<<endl;
			CFSO rstd(3, 1.0, {0.0, 0.0, 0.0, 0.0}, {0.75, 0.0, -0.25});
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
}