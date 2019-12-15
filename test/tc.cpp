#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

using namespace Catch::literals;
using namespace std;

#include "CFSData.hpp"

#define FPT double
#define SEQ std::vector<FPT>
#define CFSO CFST<FPT>

/*
#include "testCFSData.hpp"
#include "testCFSMatch.hpp"
#include "testSubtraction.hpp"
#include "testAmplitude.hpp"
#include "testToleratedEquality.hpp"
#include "testAddition.hpp"
#include "testConvertFrom.hpp"
#include "testConvertTo.hpp"
#include "testIntegral.hpp"
#include "testTransformTo.hpp"
#include "testFunctionValue.hpp"
#include "testLinSolve.hpp"
#include "testMultiplication.hpp"
#include "testPower.hpp"*/
#include "testFunction.hpp"