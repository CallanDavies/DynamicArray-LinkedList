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
			Node* node = new Node();
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
	void push_back(const T & value)
	{
		Node<T>* temp = new Node();
		temp->next = nullptr;
		temp->previous = nullptr;
		temp->value = value;

		m_last = temp;
	}

	// add a new value to the start of the list
	void push_front(const T & value)
	{
		Node<T>* temp = new Node();
		temp->next = nullptr;
    	temp->previous = nullptr;
		temp->value = value;

		m_first = temp;
	}

	//remove the last element
	void pop_back()
	{
		delete m_last;
	}

	// remove the first element
	void pop_front()
	{
		delete m_first;
	}

	// return a Boolean, true if the list is empty, false otherwise
	bool empty()
	{
		if (m_elements == 0)
		{
			return true;
		}
		return false;
	}

	//remove all elements from the list
	void clear()
	{

	}

	// remove all elements with matching value
	void remove(T* a_value)
	{

	}
	private:

		//Sentinel nodes
		Node<T>* m_first = nullptr;
		Node<T>* m_last = nullptr;

		int m_elements = 0;
};