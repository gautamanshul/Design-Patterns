// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>
#include "Singleton.h"

TEST(DatabaseTests, IsSingletonTest)
{
	auto & db = Singleton::get();
	auto & db2 = Singleton::get();

	ASSERT_EQ(1, db.instance_count);
	ASSERT_EQ(1, db2.instance_count);
}

TEST(RecordFinderTest, SingletonTotalPopulationTest)
{
	SingletonRecordFinder rf;

	std::vector<std::string> names{ "Seoul", "Mexico City" };
	int tp = rf.totalPopulation(names);
	EXPECT_EQ(17500000 + 17400000, tp);
}

TEST(RecordFinderTest, DepTotalPopulationTest)
{
	DummyDb db{};
	ConfigRecFinder rf{ db };

	EXPECT_EQ(4, rf.totalPopulation(std::vector<std::string>{"alpha", "gamma"}));

}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

