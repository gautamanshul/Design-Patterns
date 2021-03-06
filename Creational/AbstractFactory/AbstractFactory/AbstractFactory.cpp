// AbstractFactory.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "HotDrink.h"
#include "DrinkFactory.h"

std::unique_ptr<HotDrink> make_drink(std::string type)
{
	std::unique_ptr<HotDrink> hd;

	if (type == "tea") {
		hd = std::make_unique<Tea>();
		hd->prepare(100);
	}
	else {
		hd = std::make_unique<Coffee>();
		hd->prepare(300);
	}

	return hd;
}

int main()
{
	auto d = make_drink("tea");

	DrinkFactory df;

	df.make_drink("Coffee");

	DrinkByVolume dv;
	dv.make_drink("tea");

	getchar();
    return 0;
}

