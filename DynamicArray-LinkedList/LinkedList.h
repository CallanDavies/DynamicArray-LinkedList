#pragma once

template <class T>
class LinkedList
{
public:
	template <class T>
	struct Node
	{
		// Data found in this node
		T value;
		//Pointer to next item
		Node* next;
		//Pointer to previous item
		Node* previous;
	};

	class Iterator
	{
	public:
		Iterator() {}
		Iterator(Node<T>* node) {}
		~Iterator() {}

		bool operator == (const Iterator& other)
		{
			return m_node == other.m_node;
		}

		bool operator != (const Iterator& other)
		{
			return m_node != other.m_node;
		}

		Iterator operator++ ()
		{
			m_node = m_node->next;
			return *this;
		}

		Iterator operator ++ (int)
		{
			Iterator temp(m_node);
			m_node = m_node->next;
			return temp;
		}
		// decrement operator
		Iterator operator -- ()
		{
			Iterator temp(m_node);
			m_node = m_node->previous;
			return temp;
		}


		// returns the value of items in the list
		T& get(){return m_node->value; }

		T& operator * () { return m_node->value; }
		T& operator -> () { return &(m_node->value); }
	private:
		Node<T>* m_node = nullptr;
	};

	// return an iterator to the first element
	Iterator begin() { return Iterator(m_first); }

	// return an interator to a null element
	Iterator end() { return Iterator(m_last); }
	
	//remove an element by its iterator
	void erase(Iterator a_iterator)
	{
		m_elements = m_elements - 1;
		Node<T>* temp = a_iterator;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}


	// add a new value one-past the specified iterator location
	void Insert(T a_value, int a_iIndex)
	{
		// Step through and creat new node, linking 
		// and setting value
		int iCount = 0;
		Node<T>* current = m_first->next;
		while (current != m_end && iCount != a_iIndex)
		{
			++iCount;
			current = current->next;
		}

		Node<T>* temp = new Node<T>();
		temp->value = a_value;

		// linking 
		temp->next = current;
		temp->previous = current->previous;
		current->previous->next = temp;
		current->previous = temp;
	}

	LinkedList() {}
	LinkedList (int startingElements) : m_elements(startingElements)
	{
		// Loop through the new list nodes
		for (int i = 0; i < m_elements; ++i)
		{
			Node<T>* node = new Node<T>();
			if (i == 0)
			{
				m_last = node;
				// make it point to the first item
				node->next = m_first;
			}
			
			if (m_first != nullptr)
			{
				m_first->previous = node;
			}
		}
	}

	~LinkedList()
	{
	}


	//return how many elements exist in the list
	int count() { return m_elements; }

	//return the value of the first element
	T* first() { return m_first->value; }

	// return the value of the first element
	T* last() { return m_last->value; }

	// add a new value to the end of the list
	void push_back(const T & a_value)
	{
		m_elements = m_elements + 1;
		Node<T>* temp = new Node<T>();
		temp->value = a_value;
		temp->next = m_first;
		temp->previous = m_first->previous;
		temp->next->previous = temp;
		temp->previous->next = temp;
	}

	// add a new value to the start of the list
	void push_front(const T & a_value)
	{
		m_elements = m_elements + 1;
		Node<T>* temp = new Node<T>();
		temp->value = a_value;
		temp->next = m_first->next;
		temp->previous = m_first;
		temp->next->previous = temp;
		temp->previous->next = temp;
	}

	//remove the last element
	void pop_back()
	{
		m_elements = m_elements - 1;
		Node<T>* temp = m_first->previous;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}

	// remove the first element
	void pop_front()
	{
		m_elements = m_elements - 1;
		Node<T>* temp = m_first->next;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
	}

	// return a Boolean, true if the list is empty, false otherwise
	bool empty() { return m_first->next == m_first; }
	

	//remove all elements from the list
	void clear()
	{
		
	}

	// remove all elements with matching value
	void remove(T* a_value)
	{
		Node<T>* temp = m_first->next;
		while (temp != head)
		{
			Node<T>* next = temp->next;
			if (temp->value == a_value)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				delete temp;
				m_elements = m_elements - 1;
			}
			temp = next;
		}
	}
	private:

		//Sentinel nodes
		Node<T>* m_first = nullptr;
		Node<T>* m_last = nullptr;

		int m_elements = 0;
};