#pragma once
#include "Node.h"


template <class T>
class LinkedList 
{
private:
	//Sentinel nodes
	Node<T>* m_start;
	Node<T>* m_end;

public:
	//Constructor
	LinkedList()
	{
		m_start = new Node<T>();
		m_end = new Node<T>();

		//Link to eachother
		m_start->m_Next = m_end;
		m_start->m_Previous = nullptr;

		m_end->m_Next = nullptr;
		m_end->m_Previous = m_start;
	}

	~LinkedList()
	{
		delete m_start;
		m_start = nullptr;
		delete m_end;
		m_end = nullptr;
	}


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











