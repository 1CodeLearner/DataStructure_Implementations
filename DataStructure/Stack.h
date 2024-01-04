#pragma once
#include <string>
#include <memory>

class Stack
{
public:
	Stack();
	Stack(const Stack& other) = delete;
	int Pop();
	void Push(std::string value);
	bool IsEmpty();

	struct Node 
	{
		Node(std::string str)
			: strValue(str)
		{}
		std::string strValue;
		std::unique_ptr<Node> next;
	};
private:
	std::unique_ptr<Node> Top;
};

