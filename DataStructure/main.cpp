
#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <crtdbg.h>

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

int main()
{
	//LinkedListExample();

	DoublyLinkedList<int> dll;
	dll.PushFront(10);


	//_CrtDumpMemoryLeaks();
	return 0;
}