#include <iostream>

#include "LinkedList.h"

void main()
{
	LinkedList<int>myList;
	LinkedList<int>myList2(10);

//	myList2.push_back(22);
//	myList2.push_front(25);

	for (auto i = myList.begin(); i != myList.end(); ++i)
	{
		std::cout << i.get() << std::endl;
	}

}