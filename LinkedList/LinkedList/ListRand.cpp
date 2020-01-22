#include "ListRand.h"
#include <cassert> 
#include <fstream>
#include <iostream>
#include <random>
#include <unordered_map>


void ListRand::Serialize(std::ostream& stream)
{
	if (!stream)
		return;

	if (Empty())
		return;

	stream << count << std::endl;
	std::unordered_map<ListNode*, int> offsetRandNode;

	int nodeIdx = 0;
	for (auto node = head; node != nullptr; node = node->next) {
		stream << node->data << std::endl;
		offsetRandNode.insert({ node, nodeIdx++ });
	}

	for (auto node = head; node != nullptr; node = node->next) {
		stream << offsetRandNode[node->rand] << std::endl;
	}
}

void ListRand::Deserialize(std::istream& stream)
{
	if (!stream)
		return;

	Clear();

	int length = 0;
	stream >> length;
	if (length <= 0)
		return;

	std::vector< ListNode*> offsetRandNode;
	offsetRandNode.reserve(length);

	std::string data;
	for (int i = 0; i < length; ++i) {
		assert(stream.good());
		stream >> data;
		PushBack(data);
		offsetRandNode.push_back(tail);
	}

	int idx;
	for (auto node = head; node != nullptr; node = node->next) {
		assert(stream.good());
		stream >> idx;
		assert(idx >= 0 && idx < count);
		node->rand = offsetRandNode[idx];
	}
}

bool ListRand::Empty()
{
	if (count == 0)
		return true;
	return false;
}

void ListRand::Clear()
{
	if (Empty())
		return;

	for (auto node = head; node != nullptr; node = node->next) {
		if (node->prev != nullptr)
			delete node->prev;
	}

	if (tail)
		delete tail;

	head = tail = nullptr;
	count = 0;
}

void ListRand::PushBack(const std::string & data)
{
	if (!head) {
		head = new ListNode();
		head->data = data;
		tail = head;
		head->next = head->prev = nullptr;
	}
	else {
		tail->next = new ListNode();
		tail->next->prev = tail;
		tail = tail->next;
		tail->next = nullptr;
		tail->data = data;
	}
	++count;
}

void ListRand::SetRandPointer()
{
	if (Empty())
		return;

	std::vector< ListNode*> offsetRandNode;
	offsetRandNode.reserve(count);

	int nodeIdx = 0;
	for (auto node = head; node != nullptr; node = node->next)
		offsetRandNode.push_back(node);

	std::random_device rd;
	std::uniform_int_distribution<int> uid(0, count - 1);
	for (auto node = head; node != nullptr; node = node->next) {
		int randIdx = uid(rd);
		node->rand = offsetRandNode[randIdx];
	}
}

void ListRand::Print()
{
	if (Empty())
		return;

	for (auto node = head; node != nullptr; node = node->next)
		std::cout << "data = " << node->data << ": rand data = " << node->rand->data << std::endl;
}

void ListRand::PrintToFile(const std::string listRandFileName)
{
	if (Empty())
		return;

	std::ofstream outFile(listRandFileName.c_str());
	if (!outFile.is_open())
		return;

	for (auto node = head; node != nullptr; node = node->next)
		outFile << "data = " << node->data << ": rand data = " << node->rand->data << std::endl;

	outFile.close();

	std::cout << "Print ListRand to " << listRandFileName << ". Format: current data : rand pointer data" << std::endl;
}