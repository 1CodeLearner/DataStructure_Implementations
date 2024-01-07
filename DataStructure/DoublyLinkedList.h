#pragma once
#include <iostream>
#include <assert.h>

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() = default;

	DoublyLinkedList(const DoublyLinkedList& other)
	{
		*this = other;
	}
	DoublyLinkedList& operator=(const DoublyLinkedList& other)
	{
		if (this != &other)
		{
			if (!other.IsEmpty())
			{
				delete Head;
				Node<T>* temp = other.Head;
				Node<T>* newTemp = new Node<T>(temp->value);
				Head = newTemp;
				while (temp->next)
				{
					Node<T>* prevTemp = newTemp;
					temp = temp->next;
					newTemp = new Node<T>(temp->value);
					prevTemp->next = newTemp;
				}
			}

		}
		return *this;
	}

	DoublyLinkedList(DoublyLinkedList&& other)
		noexcept
	{
		*this = std::move(other);
	}
	DoublyLinkedList& operator=(DoublyLinkedList&& other)
		noexcept
	{
		if (this != &other)
		{
			Head = other.Head;
			other.Head = nullptr;
		}
		return *this;
	}

	~DoublyLinkedList()
	{
		while (Head != nullptr)
		{
			Node<T>* temp = Head->next;
			delete Head;
			Head = temp;
		}
	}

public:
	T Front();
	void PushFront(const T& value);
	void PopFront();
	bool IsEmpty();
	bool IsEmpty() const;

private:
	template <typename U>
	class Node
	{
	public:
		Node() = default;
		Node(U value)
			: value(value), next(nullptr)
		{}
		U value = U();
		Node* next = nullptr;
	};

	Node<T>* Head = nullptr;
};


template<typename T>
T DoublyLinkedList<T>::Front()
{
	assert(!IsEmpty());
	return Head->value;
}

template <typename T>
void DoublyLinkedList<T>::PushFront(const T& value)
{
	Node<T>* temp = new Node<T>(value);
	if (IsEmpty())
	{
		Head = temp;
		return;
	}

	temp->next = Head;
	Head = temp;
}

template<typename T>
void DoublyLinkedList<T>::PopFront()
{
	if (IsEmpty())
		return;

	Node<T>* temp = Head;
	Head = temp->next;
	delete temp;
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty()
{
	return Head == nullptr;
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty() const
{
	return Head == nullptr;
}
