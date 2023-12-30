#pragma once
#include <iostream>
#include <assert.h>

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() = default;

	/*
	DoublyLinkedList(const DoublyLinkedList& other)
	{
		*this = other;
	}
	DoublyLinkedList& operator=(const DoublyLinkedList& other)
	{
		if (this != *other)
		{
			if (!other.IsEmpty())
			{
				delete Head;
				/*Node<T>* temp = other.Head;
				while (temp)
				{
					Node<T>* newTemp = new Node<T>(temp->value);
					if(temp->prev)
					{
						
					}
					temp = temp->next;
				}#1#
			}

		}
		return *this;
	}

	DoublyLinkedList(const DoublyLinkedList&& other)
	{
		*this = std::move(other);
	}
	DoublyLinkedList& operator=(const DoublyLinkedList&& other)
	{
		if (this != *other)
		{
			Head = other.Head;
			//End = other.End;
		}
		return *this;
	}
	*/

	~DoublyLinkedList()
	{
		while(Head)
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

private:
	template <typename U>
	class Node
	{
	public:
		Node() = default;
		Node(U value)
			: value(value)
		{}
		U value = 0;
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
	if (IsEmpty())
	{
		Node<T>* temp = new Node<T>(value);
		Head = temp;
		return;
	}
}

template<typename T>
void DoublyLinkedList<T>::PopFront()
{
	if (IsEmpty())
		return;
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty()
{
	return Head == nullptr;
}
