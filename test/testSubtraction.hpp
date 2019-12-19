#pragma once

#include "Subtraction.hpp"

using namespace FSL;

SCENARIO("Subtraction test", "[BasicOp]")
{
	WHEN("Two CFS with same n and omega are given")
	{
		CFSO f(2, 1.0, {1.0, 0.0, 0.0}, {0.0, 1.0});
		CFSO g(2, 1.0, {0.0, 2.0, 1.0}, {1.0, 0.0});
		THEN("The result shall be the following values")
		{
			auto res = Subtraction<double>(f, g);
			REQUIRE(res.getn()==2);
			REQUIRE(res.getomega()==1.0_a);
			REQUIRE(res.getA()==SEQ{1.0, -2.0, -1.0});
			REQUIRE(res.getB()==SEQ{-1.0, 1.0});
		}
	}
}