#pragma once

#include <string>

struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand; // ������������ ������� ������� ������
	std::string data;
};


class ListRand {
public:
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int count = 0;

	void Serialize(std::ostream & stream);
	void Deserialize(std::istream & stream);

	bool Empty();
	void Clear();
	void PushBack(const std::string& data);
	void SetRandPointer();
	void Print();
	void PrintToFile(const std::string& listRandFileName);
};
