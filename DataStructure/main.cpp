
#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <crtdbg.h>
#include <stack>
#include "Stack.h"
#include "QueueArray.h"

// Call _CrtDumpMemoryLeaks after main has returned and before program terminates.
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

int main()
{
	//LinkedListExample();
	//DoublyLinkedListExample();
	//CheckUniformParenthesesWithStack("(({[[]]}))");

	QueueArray<int*> queueArr(5);
	for (int i = 0; i < 3; ++i) {
		int* value = new int(10 + i);
		queueArr.Enqueue(value);
	}
	queueArr.Dequeue(); // 
	std::cout << queueArr.Front() << std::endl;
	std::cout << (queueArr.IsEmpty() ? "True" : "False") << std::endl;
	queueArr.Dequeue();
	queueArr.Dequeue(); //set front and rear to -1


	return 0;
}