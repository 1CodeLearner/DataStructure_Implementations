#pragma once

class Node;

template<typename T>
class BST
{
public:
	BST() = default;

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

	void Add(T Value);

	const Node* Find(T Value);

	void Delete(T Value);

	~BST();

private:
	Node* Root = nullptr;

	Node* AddRecursive(Node* node, T Value);

	Node* FindRecursive(Node* node, T Value);

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
const typename BST<T>::Node* BST<T>::Find(T Value)
{
	return FindRecursive(Root, Value);
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

	if (Value < node->Value)
	{
		node->Left = AddRecursive(node->Left, Value);
	}
	else if (Value > node->Value)
	{
		node->Right = AddRecursive(node->Right, Value);
	}

	return node;
}

template<typename T>
typename BST<T>::Node* BST<T>::FindRecursive(Node* node, T Value)
{
	if (!node)
	{
		return nullptr;
	}

	if (Value < node->Value)
	{
		return FindRecursive(node->Left, Value);
	}
	else if (Value > node->Value)
	{
		return FindRecursive(node->Right, Value);
	}

	return node;

}

template<typename T>
typename BST<T>::Node* BST<T>::DeleteNode(Node* node)
{
	if (!node)
		return nullptr;

	DeleteNode(node->Left);
	DeleteNode(node->Right);

	delete node;
}
