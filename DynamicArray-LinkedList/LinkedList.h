#pragma once

#include "Node.h"


template <class T>
class LinkedList 
{



	void Insert(T a_data, int a_iIndex)
	{
		// Step through and creat new node, linking 
		// and setting value
		int iCount = 0;
		Node<T>* current = m_start->m_Next;
		while (current != m_end && iCount != a_iIndex)
		{
			++iCount;
			current = current->m_Next;
		}

		Node<T>* temp = new Node<T>();
		temp->m_data = a_data;

		// linking 
		temp->m_Next = current;
		temp->m_Previous = current->m_Previous;
		current->m_Previous->m_Next = temp;
		current->m_Previous = temp;
	}

	//Clear all nodes from the list
	void Clear()
	{

	}
};











