#pragma once

#include "Function.hpp"
#include "Multiplication.hpp"
#include "ToleratedEquality.hpp"
#include "Addition.hpp"

using namespace FSL;

SCENARIO("Function test", "[AdvancedOp]")
{
	WHEN("Given a CFS and a function")
	{
		CFSO x(2, 1.0, {0.0, 1.0, 0.0}, {0.0, 0.0});
		auto func = expDeriv<FPT>;
		THEN("The function shall be calculated accordingly")
		{
			auto res = Function(x, func);
			CFSO one(2, 1.0, {1.0, 0.0, 0.0}, {0.0, 0.0});
			CFSO half(2, 1.0, {0.5, 0.0, 0.0}, {0.0, 0.0});
			auto rstd = one;
			rstd = Addition(rstd, x);
			rstd = Addition(rstd, Multiplication(half, Multiplication(x, x)));
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
}