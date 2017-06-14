#include <iostream>
#include "LinkedList.h"

void Pause();

void main()
{
	
	LinkedList<int>myList;
	LinkedList<int>myList2(10);

	myList2.push_back(22);
	myList2.push_front(25);
	if (myList2.empty())
	{
		std::cout << "List is empty!" << std::endl;
	}
	else
	{
		std::cout << "List is not empty!" << std::endl;
	}
	myList2.pop_back();
	std::cout << "Pop_back performed" << std::endl;
	myList2.pop_front();
	std::cout << "Pop_front performed" << std::endl;

	myList2.push_back(2);
	myList2.push_front(30);

	std::cout << "The first value is now " << myList2.first() << std::endl; // Should output 30
	std::cout << "The last value is now  " << myList2.last() << std::endl; // Should output 20

	myList2.Insert(10, 2);
	std::cout << "Inserting value 10 to iterator 2" << std::endl;

	std::cout << "Removing all Nodes with a value equal to 10" << std::endl;
	myList2.remove(10);

	std::cout << "Clearing all nodes" << std::endl;
	myList2.clear();
	


	Pause();
}

void Pause()
{
	if (std::cin.bad())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	}
	std::cout << "Press enter to close the program..." << std::endl;
	std::cin.get();
}