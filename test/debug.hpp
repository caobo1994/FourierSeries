#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
void msg(string s)
{
	cout<< "MSG: "<<s<< endl;
}
void error(string s)
{
	cerr<<"ERROR: "<<s<<endl;
}