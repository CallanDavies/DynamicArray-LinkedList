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



	// Add a new value(a_data) to the front of the list
	void PushFront(T* a_data)
	{

	}
    
	// Add a new value(a_data) to the end of the list
	void PushBack(T* a_data)
	{

	}

	// Add a new value(a_data) one-past the specified iterator location(a_iIndex)
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

	// return an iterator to the first element
	int Begin()
	{

	}

	// return an iterator to a null element
	int End()
	{
		
	}

	// return the first element by value, assert if no elements
	T* First()
	{
		if (Empty)
		{
			
		}

	}

	// return the last element by value, assert if no elements
	T* Last()
	{
		if (Empty)
		{
			
		}

	}

	// return how many elements exist in the list
	int Count()
	{

	}

	// remove an element by its iterator(a_iIndex)
	void Erase(int a_iIndex)
	{

	}
	// remove all elements with matching value(a_data)
	void Remove(T* a_data)
	{

	}

	// remove the last element
	void PopBack()
	{

	}

	//remove the first element
	void PopFront()
	{

	}

	// return a Boolean, true if the list is empty, false otherwise
	bool Empty()
	{
		if (m_start == nullptr)
		{
			return true;
		}
		return false;
	}

	//Clear all nodes from the list
	void Clear()
	{
		for (int i = 0; i < m_end; ++i)
		{

		}
	}
};











