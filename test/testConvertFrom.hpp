#pragma once

#include "ConvertFrom.hpp"

using namespace FSL;

SCENARIO("ConvertFrom test", "[Conversion]")
{
	WHEN("Given a set of data")
	{
		size_t n = 2;
		FPT omega = 1.0;
		SEQ A{1.0, 0.0, 2.0};
		SEQ B{0.0, 1.0};
		THEN("Their conversion shall have the same data")
		{
			auto x = ConvertFrom(n, omega, A, B);
			REQUIRE(x.getn()==n);
			REQUIRE(x.getomega()==omega);
			REQUIRE(x.getA()==A);
			REQUIRE(x.getB()==B);
		}
	}
}