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

	Node* DeleteRecursive(Node* node, T Value);

	void DeleteNodes(Node* node);

	Node* FindParentRecursive(Node* node, T Value);
};

template<typename T>
BST<T>::~BST()
{
	DeleteNodes(Root);
}

template<typename T>
void BST<T>::DeleteNodes(Node* node)
{
	if (!node)
		return;

	DeleteNodes(node->Left);
	DeleteNodes(node->Right);

	delete node;
}

template<typename T>
void BST<T>::Add(T Value)
{
	Root = AddRecursive(Root, Value);
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
const typename BST<T>::Node* BST<T>::Find(T Value)
{
	return FindRecursive(Root, Value);
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
void BST<T>::Delete(T Value)
{
	Root = DeleteRecursive(Root, Value);
}

template<typename T>
typename BST<T>::Node* BST<T>::DeleteRecursive(Node* node, T Value)
{
	if (!node)
		return nullptr;

	if (Value < node->Value)
	{
		node->Left = DeleteRecursive(node->Left, Value);
	}
	else if (Value > node->Value)
	{
		node->Right = DeleteRecursive(node->Right, Value);
	}
	else
	{
		if (!node->Right && !node->Left)
		{
			Node* temp = node;
			node = nullptr;
			delete temp;
		}
		else if (node->Right && node->Left)
		{
			Node* temp = node->Right;
			while (temp->Left)
			{
				temp = temp->Left;
			}
			node->Value = temp->Value;
			node->Right = DeleteRecursive(node->Right, temp->Value);
		}
		else if (node->Right)
		{
			Node* temp = node;
			node = node->Right;
			delete temp;
		}
		else
		{
			Node* temp = node;
			node = node->Left;
			delete temp;
		}
	}

	return node;
}

template<typename T>
typename BST<T>::Node* BST<T>::FindParentRecursive(Node* node, T Value)
{
	if (!node)
	{
		return nullptr;
	}

	if (Value < node->Value)
	{
		if (node->Left->Value == Value)
		{
			return node;
		}
		else
		{
			return FindParentRecursive(node->Left, Value);
		}
	}
	else if (Value > node->Value)
	{
		if (node->Right->Value == Value)
		{
			return node;
		}
		else
		{
			return FindParentRecursive(node->Right, Value);
		}
	}
}
