#pragma once

#include "Division.hpp"
#include "ToleratedEquality.hpp"

using namespace FSL;

SCENARIO("Division test", "[BasicOp]")
{
	WHEN("Given two CFS sin2 and cos")
	{
		CFSO f(2, 1.0, {0.0, 0.0, 0.0}, {0.0, 1.0});
		CFSO g(2, 1.0, {0.0, 1.0, 0.0}, {0.0, 0.0});
		THEN("The division result shall be 2*sin")
		{
			CFSO rstd(2, 1.0, {0.0, 0.0, 0.0}, {2.0, 0.0});
			auto res = Division(f, g);
			std::cout<<res<<endl;
			CHECK(ToleratedEquality(rstd, res, 0.000001));
		}
	}
}