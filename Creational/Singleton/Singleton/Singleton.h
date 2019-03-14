#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Database {
public:
	virtual int get_population(const std::string &name) = 0;
};

class Singleton : public Database
{
	Singleton()
	{
		std::cout << "Initializing Database" << std::endl;

		std::ifstream ifs("capitals.txt");

		std::string s, s2;
		while (getline(ifs, s)) {
			getline(ifs, s2);
			int num = std::stoi(s2);
			caps[s2] = num;
		}
		instance_count++;
	}
	std::map<std::string, int> caps;

public:
	static int instance_count;
	Singleton(Singleton const &) = delete;
	void operator = (Singleton &) = delete;
	
	static Singleton & get() {
		static Singleton db;
		return db;
	}

	int get_population(const std::string &name) override {
		
		return caps[name];
	}
};

int Singleton::instance_count = 0;

//Finds all the cities in database and gives the total population
struct SingletonRecordFinder
{
	int totalPopulation(std::vector<std::string> names)
	{
		int result = 0;
		for (auto & name : names) {
			result += Singleton::get().get_population(name);
		}

		return result;
	}
};

class DummyDb : public Database
{
	std::map<std::string, int> caps;
public:
	DummyDb() {
		caps["alpha"] = 1;
		caps["beta"] = 2;
		caps["gamma"] = 3;
	}

	int get_population(const std::string &name) override {
		return caps[name];
	}
};

struct ConfigRecFinder
{
	Database &db;
	
	ConfigRecFinder(Database &db) : db{ db } {}
	
	int totalPopulation(std::vector<std::string> names)
	{
		int result = 0;
		for (auto & name : names) {
			result += db.get_population(name);
		}

		return result;
	}

};