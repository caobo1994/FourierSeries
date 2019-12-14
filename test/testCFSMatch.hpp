#pragma once

#include "CFSMatch.hpp"

using namespace FSL;

SCENARIO("CFSMatch test", "[BasicOp]")
{
	WHEN("Given two matching CFS")
	{
		CFSO f(2, 1.0);
		CFSO g(2, 1.0);
		THEN("They should be confirmed match")
		{
			REQUIRE(CFSMatch(f, g));
		}
	}
	WHEN("Gvien two CFS with different n")
	{
		CFSO f(2, 1.0);
		CFSO g(1, 1.0);
		THEN("They should not match")
		{
			REQUIRE(!CFSMatch(f, g));
		}		
	}
	WHEN("Given two CFS with different omega")
	{
		CFSO f(2, 1.0);
		CFSO f(2, 0.5);
		THEN("They should not match")
		{
			REQUIRE(!CFSMatch(f, g));
		}
	}
	WHEN("Given two CFS with different n and omega")
	{
		CFSO f(2, 1.0);
		CFSO g(1, 0.5);
		THEN("They should not match")
		{
			REQUIRE(!CFSMatch(f, g));
		}
	}
}
