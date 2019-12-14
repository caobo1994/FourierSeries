#pragma once

#include "Addition.hpp"
#include "ToleratedEquality.hpp"

using namespace FSL;

SCENARIO("Addition test", "[BasicOp]")
{
	WHEN("Given two CFS")
	{
		CFSO f(2, 1.0, {0.0, 2.0, 0.0}, {-2.0, 0.0});
		CFSO g(2, 1.0, {1.0, 0.0, 2.0}, {0.0, 1.0});
		THEN("Result shall be rstd within tol")
		{
			CFSO res = Addition(f, g);
			CFSO rstd(2, 1.0, {1.0, 2.0, 2.0, -2.0, 1.0});
			REQUIRE(ToleratedEquality(res, rstd, 0.000001)==true);
		}
	}	
}