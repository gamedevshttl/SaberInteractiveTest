#include "TestListRand.h"
#include <fstream>
#include <iostream>

bool TestListRand::GenerateListRand(const std::string& testContentFileName)
{
	std::ifstream outFile(testContentFileName.c_str());
	if (!outFile.is_open()) {
		std::cout << "can't open " << testContentFileName << std::endl;
		return false;
	}

	std::string word;
	while (outFile >> word) {
		listRand.PushBack(word);
	}
	outFile.close();

	listRand.SetRandPointer();
	std::cout << "Generate ListRand" << std::endl;
	return true;
}

void TestListRand::Serialize()
{
	std::ofstream outFile("SerializeListRand.txt");	
	if (!outFile.is_open())
		return;

	listRand.Serialize(outFile);
	outFile.close();

	std::cout << "Serialize RandList to SerializeListRand.txt" << std::endl;
}

void TestListRand::Deserialize()
{
	std::ifstream inFile("SerializeListRand.txt");
	if (!inFile.is_open())
		return;

	listRand.Deserialize(inFile);
	inFile.close();	

	std::cout << "Deserialize RandList form SerializeListRand.txt" << std::endl;
}

void TestListRand::SimpleTest()
{
	std::cout << "SimpleTest" << std::endl;

	listRand.Clear();
	for (int i = 0; i < 10; ++i)
		listRand.PushBack(std::to_string(i));

	listRand.SetRandPointer();

	std::cout << "Generated list" << std::endl;
	listRand.Print();

	std::ofstream outFile("SerializeSimpleListRand.txt");
	listRand.Serialize(outFile);
	outFile.close();

	std::cout << std::endl;

	std::ifstream inFile("SerializeSimpleListRand.txt");
	listRand.Deserialize(inFile);
	inFile.close();

	std::cout << "Deserialize list" << std::endl;
	listRand.Print();

	std::cout << std::endl;
}

void TestListRand::RunMainTest1(const std::string& testContentFileName)
{
	std::cout << "Main test1" << std::endl;
	listRand.Clear();
	if (!GenerateListRand(testContentFileName)) {
		std::cout << "can't create ListRand"<<std::endl;
		return;
	}
	listRand.PrintToFile("GeneratedListRand.txt");
	Serialize();
	Deserialize();
	listRand.PrintToFile("DeserializeListRand.txt");
	std::cout << std::endl;
}

void TestListRand::RunMainTest2(const std::string& testContentFileName)
{
	std::cout << "Main test2" << std::endl;
	listRand.Clear();
	if (!GenerateListRand(testContentFileName)) {
		std::cout << "can't create ListRand" << std::endl;
		return;
	}

	Serialize();
	listRand.PrintToFile("GeneratedListRand.txt");
	std::cout << std::endl;
}

void TestListRand::RunMainTest3()
{
	std::cout << "Main test3" << std::endl;
	Deserialize();
	listRand.PrintToFile("DeserializeListRand.txt");
	std::cout << std::endl;
}