#pragma once

#include "ToleratedEquality.hpp"

using namespace FSL;

SCENARIO("ToleratedEquality test", "[AdvancedOp]")
{
	WHEN("Two given CFS")
	{
		CFSO f(2, 1.0, {1.0, 0.0, 0.0}, {0.0, 1.0});
		CFSO g(2, 1.0, {0.0, 2.0, 1.0}, {1.0, 0.0});
		THEN("They shall not be equal with epsilon == 1")
		{
			REQUIRE(ToleratedEquality(f, g, 1.0)==false);
		}
		THEN("They shall be equal with epsilon == 10")
		{
			REQUIRE(ToleratedEquality(f, g, 10.0)==true);
		}
	}	
}