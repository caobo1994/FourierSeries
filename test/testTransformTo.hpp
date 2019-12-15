#pragma once

#include "TransformTo.hpp"
#include "ToleratedEquality.hpp"
#include <cmath>

using namespace FSL;

SCENARIO("TransformTo test", "[Transform]")
{
	WHEN("Given an even function, n, and omega")
	{
		auto f = [](FPT x){return x*x;};
		size_t n = 2;
		FPT omega = 1.0;
		THEN("The CFS res shall match the rstd")
		{
			CFSO rstd(2, 1.0, {M_PI*M_PI/3, -4.0, 1.0}, {0.0, 0.0});
			REQUIRE(ToleratedEquality(TransformTo(f, n, omega), rstd, 0.01));
		}
	}
	WHEN("Given an odd function, n, and omega")
	{
		auto f = [](FPT x){return x;};
		size_t n = 2;
		FPT omega = 1.0;
		THEN("The CFS res shall match the rstd")
		{
			CFSO rstd(2, 1.0, {0.0, 0.0, 0.0}, {2.0, -1.0});
			REQUIRE(ToleratedEquality(TransformTo(f, n, omega), rstd, 0.01));
		}
	}

}