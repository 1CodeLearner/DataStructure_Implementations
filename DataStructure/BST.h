#pragma once

template<typename T>
class BST
{
public:
	BST() = default;

	void Add(T Value);

	T Find(T Value);

	void Delete(T Value);

	~BST();

private:

	class Node
	{
	public:
		Node(T _Value)
			:
			Value(_Value), Left(nullptr), Right(nullptr) {}

		T Value;
		Node* Left;
		Node* Right;
	};

	Node* Root = nullptr;

	Node* AddRecursive(Node* node, T Value);

	Node* DeleteNode(Node* node);
};


template<typename T>
BST<T>::~BST()
{
	Root = DeleteNode(Root);
	delete Root;
}
template<typename T>
void BST<T>::Add(T Value)
{
	Root = AddRecursive(Root, Value);
}

template<typename T>
T BST<T>::Find(T Value)
{
	return T();
}

template<typename T>
void BST<T>::Delete(T Value)
{
}

template<typename T>
typename BST<T>::Node* BST<T>::AddRecursive(Node* node, T Value)
{
	if (!node)
	{
		return new Node(Value);
	}

	if(Value < node->Value)
	{
		node->Left = AddRecursive(node->Left, Value);
	}
	else if(Value > node->Value)
	{
		node->Right = AddRecursive(node->Right, Value);
	}

	return node;
}

template<typename T>
typename BST<T>::Node* BST<T>::DeleteNode(Node* node)
{
	if(!node)
		return nullptr;

	DeleteNode(node->Left);
	DeleteNode(node->Right);

	delete node;
}
