
#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <crtdbg.h>
#include <random>
#include <stack>
#include "Stack.h"
#include "QueueArray.h"
#include "QueueLinked.h"
#include "BST.h"
#include <unordered_map>
#include <sstream>
#include <random>

//Call _CrtDumpMemoryLeaks after main has returned and before program terminates.
struct AtExit
{
	~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

void LinkedListExample()
{
	LinkedList<int> list;

	std::cout << "========================LinkedList===========================" << '\n';

	std::cout << list.Size() << std::endl;
	std::cout << "Empty?: " << (list.Empty() ? "true" : "false") << std::endl;
	std::cout << "\n";

	list.Add(10); // 10
	list.Add(20); // 10,20
	list.Add(30); // 10,20,30
	std::cout << "Print after Add: ";
	list.Print();

	list.Insert(5, 3); // 10, 20, *5, 30
	list.Insert(15, 5); // 10, 20, 5, 30, *15
	list.Insert(25, 2); // 10, *25, 20, 5, 30, 15
	list.Insert(-1, 10); // 10, 25, 20, 5, 30, 15, *-1
	list.Insert(50, 7); // 10, 25, 20, 5, 30, 15, *50, -1
	list.Insert(90, 9); // 10, 25, 20, 5, 30, 15, 50, -1, *90
	std::cout << "Print after Insert: ";
	list.Print();

	list.Delete(3); // 10, 25, 5, 30, 15, 50, -1, 90
	list.Delete(5); // 10, 25, 5, 30, 50, -1, 90
	list.Delete(20); // 10, 25, 5, 30, 50, -1
	list.Delete(-10); // 25, 5,	 30, 50, -1
	std::cout << "Print after Delete: ";
	list.Print();

	list.Reverse(true); // 25, 5, 30, 50, -1
	std::cout << "Print after reversing recursively: ";
	list.Print();

	list.Reverse(); // -1, 50, 30, 5, 25
	std::cout << "Print after reversing iteratively: ";
	list.Print();

	std::cout << "Print (recursive): ";
	list.Print(true);

	std::cout << "\n";

	std::cout << "Print in reverse (recursive): ";
	list.PrintReverse(true);

	std::cout << "\n";
	std::cout << "\n";
	std::cout << list.Size() << std::endl;
	std::cout << "Empty?: " << (list.Empty() ? "true" : "false") << std::endl;

	std::cout << "===================================================" << '\n';
}

void DoublyLinkedListExample() {
	DoublyLinkedList<int> dll;
	dll.PushFront(10);
	dll.PushFront(20);
	dll.PushFront(30);
	DoublyLinkedList<int> dll2 = std::move(dll);
	//std::cout << dll.Front() << std::endl;

	std::cout << dll2.Front() << std::endl;
	dll2.PopFront();

	//std::cout << dll.Front() << std::endl;
	std::cout << dll2.Front() << std::endl;

}

void CheckUniformParenthesesWithStack(std::string uniformParentheses)
{
	Stack<char> stackDT;

	bool isUniform = true;
	for (auto c : uniformParentheses)
	{
		switch (c)
		{
		case 41:
		{
			if (stackDT.CheckTop() != 40 || stackDT.IsEmpty())
				isUniform = false;
			else
				stackDT.Pop();
			break;
		}
		case 93:
		{
			if (stackDT.CheckTop() != 91 || stackDT.IsEmpty())
				isUniform = false;
			else
				stackDT.Pop();
			break;
		}
		case 125:
		{
			if (stackDT.CheckTop() != 123 || stackDT.IsEmpty())
				isUniform = false;
			else
				stackDT.Pop();
			break;
		}
		default:
		{
			stackDT.Push(c);
			break;
		}

		}
		if (!isUniform) break;
	}

	if (isUniform) std::cout << uniformParentheses << " is uniform." << std::endl;
	else std::cout << uniformParentheses << " is not uniform." << std::endl;
}

void QueueArrayExample() {

	QueueArray<int> queueArr1(1);
	{
		QueueArray<int> queueArr(5);
		for (int i = 0; i < 5; ++i) {
			int value = 10 + i;
			queueArr.Enqueue(value);
		}
		std::cout << queueArr.Front() << std::endl;
		queueArr1 = std::move(queueArr);
	}
	//std::cout << queueArr1.Front() << std::endl;
	//queueArr1.Dequeue();
	//std::cout << queueArr1.Front() << std::endl;

	std::cout << queueArr1.ElementsNum() << std::endl;
}

void QueueLinkedExample()
{
	QueueLinked<int> QLinked;
	QLinked.Enqueue(10);
	QLinked.Enqueue(20);
	QLinked.Enqueue(30);
	QLinked.Enqueue(40);
	QLinked.Dequeue();
	QLinked.Dequeue();

	std::cout << QLinked.Front() << std::endl;
	std::cout << QLinked.Size() << std::endl;
}

void BinarySearchTreeExample()
{
	BST<int> bst;

	/*std::mt19937 rnd(std::random_device{}());
	std::uniform_int_distribution<int> dist(0, 5);
	for (int i = 0; i < 10000; ++i)
	{
		bst.Add(dist(rnd));
	}*/

	bst.Add(50);
	bst.Add(5);
	bst.Add(3);
	bst.Add(11);
	bst.Add(20);
	bst.Add(60);
	bst.Add(90);
	bst.Add(34);

	//bst.Delete(5);

	const BST<int>::Node* node = bst.Find(50);
	if (node)
	{
		std::cout << node->Value << std::endl;
	}
	else
	{
		std::cout << "missing" << std::endl;
	}

	int minValue = bst.Min();
	std::cout << minValue << std::endl;

	int maxValue = bst.Max();
	std::cout << maxValue << std::endl;

	int heightVal = bst.Height();
	std::cout << heightVal << std::endl;

	bst.Traverse();

	std::cout << (bst.IsBST() ? "TRUE" : "FALSE") << std::endl;

	std::cout << "Successor: " << bst.GetPredecessorOf(maxValue) << std::endl;
}

int main()
{
	//LinkedListExample();
	//DoublyLinkedListExample();
	//CheckUniformParenthesesWithStack("(({[[]]}))");
	//QueueArrayExample();
	//QueueLinkedExample();
	//CheckUniformParenthesesWithStack("(({[[]]}))");

	BinarySearchTreeExample();
	return 0;
}