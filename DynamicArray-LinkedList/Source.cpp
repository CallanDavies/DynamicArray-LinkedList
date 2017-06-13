#include <iostream>

#include "LinkedList.h"

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
}