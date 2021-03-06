// Factory.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

#include <ostream>


//enum class PointType {
//	cartesian,
//	polar
//};

//class Point {
//public:
//	float x, y;
	//When two constructors have the same signature, we might need to use an enum, but this isn't the best solution as during development, its easy
	// to forget what the type to be used when the former parameters have the same signature. For the case below, its easy to forget if the type is cartesian
	//or polar or the user may not pass the variable all together defaulting to cartesian and there is nothing in the API that indicates the type of x an y.
	/*Point(const float a, const float b, PointType type = PointType::cartesian)
	{
		if (type == PointType::cartesian) {
			x = a;
			y = b;
		}
		else {
			x = a * cos(b);
			y = a * sin(b);
		}
	}*/

//	Point(const float r)
//};

class point {
	point(const float x, const float y) : x{ x }, y{ y } {}

	class PointFactory
	{
	public:
		static point NewCartesian(const float x, const float y)
		{
			return { x, y };
		}

		static point NewPolar(const float r, const float theta)
		{
			return { r * cos(theta), r * sin(theta) };
		}
	};


public:
	float x, y;

	friend std::ostream & operator <<  (std::ostream & os, const point & obj)
	{ 
		return os << " x: " << obj.x << " y: " << obj.y;
	}

	static PointFactory Factory;
};



int main()
{

	//point p{ 1, 2 }; 
	//auto c = PointFactory::NewCartesian(1, 2);
	//auto p = PointFactory::NewPolar(5, M_PI_4);
	
	auto c = point::Factory.NewCartesian(1, 2);
	auto p = point::Factory.NewPolar(5, M_PI_4);

	std::cout << c << std::endl;

	std::cout << p << std::endl;

	getchar();
    return 0;
}

