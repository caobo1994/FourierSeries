#pragma once

#include "LinSolve.hpp"

using namespace FSL;

using MAT = std::vector<std::vector<double>>;

SCENARIO("LinSolve test", "[LinSolve]")
{
	WHEN("Given a matrix M and a vector y")
	{
		MAT M{{1.0, 1.0}, {1.0, 0.0}};
		SEQ y{3.0, 1.0};
		size_t n = 2;
		THEN("The solution shall be the mathematical oracle")
		{
			SEQ x;
			LinSolve(n, M, y, x);
			REQUIRE_THAT(x, Catch::Approx({2.0, 1.0}));
		}
	}
}