#pragma once

#include "ConvertTo.hpp"

using namespace FSL;

SCENARIO("ConvertTo test", "[Conversion]")
{
	WHEN("Given a CFS")
	{
		CFSO f(2, 1.0, {1.0, 0.0, 2.0}, {0.0, 1.0});
		THEN("Its conversion shall be the same with its data")
		{
			auto [n, omega, A, B] = ConvertTo(f);
			cout << A.size() <<endl;
			REQUIRE(n==f.getn());
			REQUIRE(omega==f.getomega());
			REQUIRE(A==f.getA());
			REQUIRE(B==f.getB());
		}
	}
}