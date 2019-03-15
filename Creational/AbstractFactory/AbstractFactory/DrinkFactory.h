#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"
#include <functional>

struct HotDrink;

class DrinkFactory {
	std::map<std::string, std::unique_ptr<HotDrinkFactory> > factories;

public:
	DrinkFactory() {
		factories["Coffee"] = std::make_unique<CoffeeFactory>();
		factories["Tea"] = std::make_unique<TeaFactory>();
	}

	std::unique_ptr<HotDrink> make_drink(const std::string  & name)
	{
		auto drink = factories[name]->make();
		drink->prepare(200);
		return drink;
	}


};

class DrinkByVolume
{
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:
	DrinkByVolume() {
		factories["tea"] = [] {
			auto tea = std::make_unique<Tea>();
			tea->prepare(100);
			return tea;
		};
	}

	std::unique_ptr<HotDrink> make_drink(const std::string  & name)
	{
		return factories[name]();
	}

};