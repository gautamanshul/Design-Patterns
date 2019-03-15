#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

struct HotDrink
{
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	void prepare(int volume) override 
	{
		std::cout << "Take tea bag, put boiling water " << volume << "ml" << std::endl;
	}
};

struct Coffee : HotDrink
{
	void prepare(int volume) override
	{
		std::cout << "Take coffee powder, put boiling water " << volume << "ml" << std::endl;
	}
};