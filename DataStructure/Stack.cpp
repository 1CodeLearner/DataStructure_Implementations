#include "Stack.h"
#include <memory>

Stack::Stack()
{
}

int Stack::Pop()
{
	return 0;
}

void Stack::Push(std::string value)
{
	if (IsEmpty()) 
	{
		Top = std::make_unique<Node>(value);
		return;
	}

	auto newNode = std::make_unique<Node>(value);
	newNode.get()->next = std::move(Top);
	Top = std::move(newNode);
}

bool Stack::IsEmpty()
{
	return !Top.get();
}
