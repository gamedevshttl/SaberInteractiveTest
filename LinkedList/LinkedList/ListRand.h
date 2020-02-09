#pragma once

#include <string>

struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand; // произвольный элемент данного списка
	std::string data;
};


class ListRand {
public:
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int count = 0;

private:
	void Copy(const ListRand& rhs);
	void Move(ListRand&& rhs);
public:

	ListRand() {}
	ListRand(const ListRand& rhs);
	ListRand& operator = (const ListRand& rhs);

	ListRand(ListRand&& rhs);
	ListRand& operator = (ListRand&& rhs);

	~ListRand();

	void Serialize(std::ostream & stream);
	void Deserialize(std::istream & stream);

	bool Empty();
	void Clear();
	void PushBack(const std::string& data);
	void SetRandPointer();
	void Print();
	void PrintToFile(const std::string& listRandFileName);
};
