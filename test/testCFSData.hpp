#pragma once

#include "CFSData.hpp"
using namespace FSL;

SCENARIO("Constructor/Getter", "[CFSData]")
{
	GIVEN("A CFS cnstructed as below.")
	{
		CFSO f(2, 1.0, {0.0, 1.0, 2.0}, {3.0, 4.0});

		WHEN("The getters with right parameters are called.")
		{
			THEN("Getters will return the right result.")
			{
				REQUIRE(f.getn()==2);
				REQUIRE(f.getomega()==1.0_a);
				REQUIRE(f.getA()==SEQ{0.0, 1.0, 2.0});
				REQUIRE(f.getB()==SEQ{3.0, 4.0});
			}
			THEN("Elememt setters will also work.")
			{
				REQUIRE(f.getAi(0)==0.0_a);
				REQUIRE(f.getAi(1)==1.0_a);
				REQUIRE(f.getAi(2)==2.0_a);
				REQUIRE(f.getBi(1)==3.0_a);
				REQUIRE(f.getBi(2)==4.0_a);
			}
		}

		WHEN("Element getters with wrong/exceptional indices are called.")
		{
			THEN("getAi shall throw.")
			{
				REQUIRE_THROWS(f.getAi(3));
			}
			THEN("getBi shall throw/return preset value.")
			{
				REQUIRE_THROWS(f.getBi(3));
				REQUIRE(f.getBi(0)==0.0_a);
			}
		}
	}
}

SCENARIO("Setters", "[CFSData]")
{
	GIVEN("A CFS is constructed as below")
	{
		CFSO f(2, 1.0, {0.0, 1.0, 2.0}, {3.0, 4.0});
		WHEN("setn is called")
		{
			auto f1 = f;
			f1.setn(1);
			THEN("n shall be set accordingly")
			{
				REQUIRE(f1.getn()==1);
			}
			THEN("A and B shall be resized and initialized")
			{
				REQUIRE(f1.getA()==SEQ{0.0, 0.0});
				REQUIRE(f1.getB()==SEQ{0.0});
			}
		}
		WHEN("setomega is called")
		{
			auto f1 = f;
			f1.setomega(2.0);
			THEN("Omega shall be set")
			{
				REQUIRE(f1.getomega()==2.0_a);	
			}
			THEN("Setomega shall throw if parameter<=0")
			{
				REQUIRE_THROWS(f1.setomega(-1.0));
				REQUIRE_THROWS(f1.setomega(0.0));
			}
		}
		WHEN("setA is called.")
		{
			auto f1 = f;
			f1.setA({1.0, 2.0, 0.0});
			THEN("A shall be set accordingly")
			{
				REQUIRE(f1.getA()==SEQ{1.0, 2.0, 0.0});
			}
			THEN("setA shall throw if size of A is wrong")
			{
				REQUIRE_THROWS(f1.setA({0.0}));
				REQUIRE_THROWS(f1.setA({0.0, 1.0, 2.0, 3.0}));
			}
		}
		WHEN("setB is called.")
		{
			auto f1 = f;
			f1.setB({4.0, 3.0});
			THEN("A shall be set accordingly");
			{
				REQUIRE(f1.getB()==SEQ{4.0, 3.0});
			}
			THEN("setB shall throw if size of B is wrong")
			{
				REQUIRE_THROWS(f1.setB({1.0}));
				REQUIRE_THROWS(f1.setB({1.0, 2.0, 3.0}));
			}
		}
		WHEN("setAi are called.")
		{
			auto f1 = f;
			f1.setAi(1, 0.0);
			THEN("The value of this place shall be changed, but not others")
			{
				REQUIRE(f1.getA()==SEQ{0.0, 0.0, 2.0});
				REQUIRE(f1.getB()==SEQ{3.0, 4.0});
			}
		}

		WHEN("setBi are called.")
		{
			auto f2 = f;
			f2.setBi(1, 0.0);
			THEN("The value of this place shall be changed, but not others")
			{
				REQUIRE(f2.getA()==SEQ{0.0, 1.0, 2.0});
				REQUIRE(f2.getB()==SEQ{0.0, 4.0});
			}
		}

		WHEN("setBi(0) is called")
		{
			auto f3 = f;
			f3.setBi(0, 1.0);
			THEN("Nothing shall be changed")
			{
				REQUIRE(f3.getA()==SEQ{0.0, 1.0, 2.0});
				REQUIRE(f3.getB()==SEQ{3.0, 4.0});
			}
		}
	}
}