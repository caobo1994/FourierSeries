#pragma once

#include "Subtraction.hpp"

using namespace FSL;

SCENARIO("Subtraction test", "[BasicOp]")
{
	WHEN("Two CFS with same n and omega are given")
	{
		CFSO f(2, 1.0);
		CFSO g(2, 1.0);
		THEN("They should match")
	}
}