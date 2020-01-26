#pragma once
#include "ListRand.h"

class TestListRand
{
public:
	bool GenerateListRand(const std::string& testContentFileName);
	void Serialize();
	void Deserialize();
	void SimpleTest();
	void RunMainTest1(const std::string& testContentFileName = "Content/TestContent.txt");
	void RunMainTest2(const std::string& testContentFileName = "Content/TestContent.txt");
	void RunMainTest3();

private:
	ListRand listRand;
};

