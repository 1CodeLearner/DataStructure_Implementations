#pragma once
#include <string>
#include <memory>

template<typename T>
class Stack
{
public:
	Stack() = default;
	Stack(const Stack& other) = delete;
	T Pop();
	void Push(T value);
	bool IsEmpty();
	bool IsEmpty() const;
	T CheckTop() const;

	template<typename U>
	struct Node 
	{
		Node(U str)
			: value(str)
		{}
		U value;
		std::unique_ptr<Node> next;
	};
private:
	std::unique_ptr<Node<T>> Top;
};

template <typename T>
T Stack<T>::Pop()
{
	if(IsEmpty()) return T();

	auto temp = std::move(Top.get()->next);
	T tempValue = Top->value;
	Top = std::move(temp);
	return tempValue;
}

template <typename T>
void Stack<T>::Push(T value)
{
	if (IsEmpty()) 
	{
		Top = std::make_unique<Node<T>>(value);
		return;
	}

	auto newNode = std::make_unique<Node<T>>(value);
	newNode.get()->next = std::move(Top);
	Top = std::move(newNode);
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return !Top.get();
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return !Top.get();
}

template<typename T>
T Stack<T>::CheckTop() const
{
	if(!IsEmpty())
		return Top->value;

	return T();
}
