#pragma once
#include <iostream>

template<typename T>
class LinkedList
{
public:
	LinkedList() = default;
	LinkedList(const LinkedList<T>& other) = delete;
	LinkedList<T>& operator=(const LinkedList<T>& other) const = delete;
	~LinkedList()
	{
		while (Head != nullptr)
		{
			Node<T>* temp = Head->next;
			delete Head;
			Head = temp;
		}
	}
public:
	void Add(T value);
	void Print(bool isRecursive = false) const;
	void Print(bool isRecursive = false);
	void PrintReverse(bool isRecursive = true) const;
	bool Empty() const;
	void Insert(T value, int nPos);
	void Reverse(bool isRecursive = false);

	int Size() const;
	void Delete(int nPos);
private:
	template<typename U>
	class Node
	{
	public:
		Node(U value)
			: data(value), next(nullptr)
		{}
		U data = U();
		Node* next = nullptr;
	};

private:
	Node<T>* Head = nullptr;
	Node<T>* Traverse(Node<T>* temp, bool bPrint = false);
	void PrintRecursion(Node<T>* temp) const;
	void PrintReverseRecursion(Node<T>* temp) const;
	void ReverseRecursion(Node<T>* currentNode);
};


template<class T>
void LinkedList<T>::Add(T value)
{
	Node<T>* temp = new Node<T>(value);
	if (Head == nullptr)
	{
		Head = temp;
	}
	else
	{
		Node<T>* temp1 = Head;
		temp1 = Traverse(temp1);
		temp1->next = temp;
		temp1 = nullptr;
	}
	temp = nullptr;
}

template<typename T>
void LinkedList<T>::Print(bool isRecursive) const
{
	if (isRecursive)
	{
		PrintRecursion(Head);
		return;
	}
	Traverse(Head, true);
}

template <typename T>
void LinkedList<T>::Print(bool isRecursive)
{
	if (isRecursive)
	{
		PrintRecursion(Head);
		return;
	}
	Traverse(Head, true);
}

template<typename T>
void LinkedList<T>::PrintReverse(bool isRecursive) const
{
	if(isRecursive)
	{
		PrintReverseRecursion(Head);
		return;
	}
}

template<typename T>
void LinkedList<T>::PrintRecursion(Node<T>* temp) const
{
	if (!temp)
		return;
	std::cout << temp->data << " ";
	PrintRecursion(temp->next);
}

template<typename T>
void LinkedList<T>::PrintReverseRecursion(Node<T>* temp) const
{
	if (!temp)
		return;
	PrintReverseRecursion(temp->next);
	std::cout << temp->data << " ";
}

template<typename T>
void LinkedList<T>::ReverseRecursion(Node<T>* currentNode)
{
	if(!currentNode->next)
	{
		Head = currentNode;
		return;
	}
	ReverseRecursion(currentNode->next);
	currentNode->next->next = currentNode;
	currentNode->next = nullptr;
}

template<typename T>
bool LinkedList<T>::Empty() const
{
	return Head == nullptr;
}

template<typename T>
void LinkedList<T>::Insert(T value, int nPos)
{
	if (nPos > Size())
	{
		nPos = Size() - 1;
	}
	else
	{
		nPos = nPos - 2;
	}

	Node<T>* temp = Head;

	for (int i = 0; i < nPos; i++)
	{
		temp = temp->next;
	}

	Node<T>* temp1 = new Node<T>(value);
	temp1->next = temp->next;
	temp->next = temp1;

	return;
}

template<typename T>
void LinkedList<T>::Reverse(bool isRecursive)
{
	if(isRecursive)
	{
		ReverseRecursion(Head);
		return;
	}
	Node<T>* currentNode = Head;
	Node<T>* prevNode = nullptr;

	while (currentNode)
	{
		Node<T>* nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	Head = prevNode;
}

template<typename T>
int LinkedList<T>::Size() const
{
	int count = 0;
	Node<T>* temp = Head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template<typename T>
void LinkedList<T>::Delete(int nPos)
{
	if (nPos <= 0)
	{
		nPos = 1;
	}
	if (nPos > Size())
	{
		nPos = Size();
	}

	Node<T>* temp = Head;
	Node<T>* temp1 = nullptr;
	if (nPos == 1)
	{
		temp1 = temp;
		Head = temp->next;
		delete temp1;

		return;
	}

	for (int i = 0; i < nPos - 2; i++)
	{
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;

	return;
}


template<typename T>
typename LinkedList<T>::Node<T>* LinkedList<T>::Traverse(Node<T>* temp, bool bPrint)
{
	if (temp)
	{
		if (bPrint)
			std::cout << temp->data << " ";
		while (temp->next != nullptr)
		{
			temp = temp->next;
			if (bPrint)
				std::cout << temp->data << " ";
		}
		if (bPrint)
			std::cout << "\n";
		return temp;
	}
	else
		return nullptr;
}
