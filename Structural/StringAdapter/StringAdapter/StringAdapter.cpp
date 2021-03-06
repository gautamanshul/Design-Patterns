// StringAdapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost\algorithm\string.hpp>
#include <string>
#include <iostream>
#include <vector>

class String {
	std::string s;
public:
	String(const std::string & s) : s{ s } {}

	String to_lower() const { 
		std::string ss{ s };
		boost::to_lower(ss);
		return ss;
	}
		
	std::vector<std::string> split(const std::string & delimiter = " ") {
		std::string ss{ s };
		std::vector<std::string> svec;
		boost::split(svec, s, boost::is_any_of(delimiter), boost::token_compress_on);

		return svec;
	}
};

int main()
{
	String ad{ "Adapter Demo" };
	auto svec = ad.split();

	for (auto s : svec) {
		std::cout << s << std::endl;
	}
	getchar();
    return 0;
	
}

