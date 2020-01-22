#include <iostream>
#include "TestListRand.h"


int main()
{
	TestListRand testListRand;
	testListRand.SimpleTest();

	//Generate RandList, Serialize, Deserialize
	testListRand.RunMainTest1();

	//Generate RandList, Serialize
	//testListRand.RunMainTest2();

	//Deserialize
	//testListRand.RunMainTest3();

	system("pause");

	return 0;
}