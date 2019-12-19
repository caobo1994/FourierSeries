#pragma once

#include "Multiplication.hpp"
#include "ToleratedEquality.hpp"

using namespace FSL;

SCENARIO("Multiplication test", "[BasicOp]")
{
	WHEN("Given cos*cos")
	{
		CFSO f(2, 1.0, {0.0, 1.0, 0.0}, {0.0, 0.0});
		CFSO g(2, 1.0, {0.0, 1.0, 0.0}, {0.0, 0.0});
		THEN("Their Multiplication shall be 0.5+0.5*cos2")
		{
			CFSO rstd(2, 1.0, {0.5, 0.0, 0.5}, {0.0, 0.0});
			CFSO res = Multiplication(f, g);
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
	WHEN("Given sin*cos2")
	{
		CFSO f(2, 1.0, {0.0, 0.0, 0.0}, {1.0, 0.0});
		CFSO g(2, 1.0, {0.0, 0.0, 1.0}, {0.0, 0.0});
		THEN("Their Multiplication shall be -0.5*sin")
		{
			CFSO rstd(2, 1.0, {0.0, 0.0, 0.0}, {-0.5, 0.0});
			CFSO res = Multiplication(f, g);
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
	WHEN("Given cos*sin2")
	{
		CFSO f(2, 1.0, {0.0, 1.0, 0.0}, {0.0, 0.0});
		CFSO g(2, 1.0, {0.0, 0.0, 0.0}, {0.0, 1.0});
		THEN("Their Multiplication shall be 0.5*sin")
		{
			CFSO rstd(2, 1.0, {0.0, 0.0, 0.0}, {0.5, 0.0});
			CFSO res = Multiplication(f, g);
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}
	WHEN("Given sin*sin")
	{
		CFSO f(2, 1.0, {0.0, 0.0, 0.0}, {1.0, 0.0});
		CFSO g(2, 1.0, {0.0, 0.0, 0.0}, {1.0, 0.0});
		THEN("Their Multiplication shall be 0.5-0.5*cos2")
		{
			CFSO rstd(2, 1.0, {0.5, 0.0, -0.5}, {0.0, 0.0});
			CFSO res = Multiplication(f, g);
			CHECK(ToleratedEquality(res, rstd, 0.000001));
		}
	}

}
