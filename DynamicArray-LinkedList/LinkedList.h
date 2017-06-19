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
		if (empty())// list is empty
		{
			Node<T>* temp = new Node<T>();
			m_first = temp;
			m_last = temp;
			temp->previous = nullptr;
			temp->next = nullptr;
			temp->value = a_value;
		}
		else // there is stuff inside the list
		{
			Node<T>* temp = new Node<T>();
			temp = m_first;


			for (int i = 0; i < a_iIndex; i++)//iterate up to the index
			{
				if (i > m_elements)// make sure we havent stepped over our list
					return;
				if (temp->next == nullptr) // make sure that the next is not a nullptr
					return;

				temp = temp->next;//set our current node in the list
			}
			temp->value = a_value; //set the value
			
			/*while (a_iIndex > temp->value && temp->next != m_last->next)
			{
				temp = temp->next;
			}*/
		}
	}

	LinkedList() {}
	LinkedList (int startingElements) : m_elements(startingElements)
	{
		Node<T>* currentNode = m_first;
		Node<T>* previousNode = nullptr;

		

		// Loop through the new list nodes
		for (int i = 0; i < m_elements; ++i)
		{
			Node<T>* node = new Node<T>();//insert into the list
			currentNode = node;
			if (m_first == nullptr)// if we're at the first element
			{
				m_first = node;
				currentNode->previous = nullptr;// set previous to null

			}
			else if (i == m_elements - 1)//we're at the end of our list
			{
				m_last = node;
				currentNode->previous = previousNode;
				previousNode->next = currentNode;
			}
			else //anywhere in the middle
			{
				currentNode->previous = previousNode;
				previousNode->next = currentNode;
			}

			previousNode = currentNode;
			currentNode = currentNode->next;

		}




			//if (i == 0)
			//{
			//	m_last = node;
			//	// make it point to the first item
			//	node->next = m_first;
			//}
			//
			//if (m_first != nullptr)
			//{
			//	m_first->previous = node;
			//}
		//}
	}

	~LinkedList()
	{
	}


	//return how many elements exist in the list
	int count() { return m_elements; }

	//return the value of the first element
	T& first() { return m_first->value; }

	// return the value of the first element
	T& last() { return m_last->value; }

	// add a new value to the end of the list
	void push_back(const T & a_value)
	{
		
		Node<T>* temp = new Node<T>();
		Node<T>* previous;
		temp->value = a_value;
		temp->next = nullptr;
		temp->previous = m_last;
	//	if (m_last != nullptr)
	//	{
	//		m_last->next = temp;
	//	}
	//	else
		previous = m_last;
		m_last = temp;
		
		previous->next = m_last;
		m_last->previous = previous;

	}

	// add a new value to the start of the list
	void push_front(const T & a_value)
	{
		
		Node<T>* temp = new Node<T>();
		Node<T>* next;
		temp->value = a_value;
		temp->next = m_first;
		temp->previous = nullptr;
		
		next = m_first;
		m_first = temp;

		next->previous = m_first;
		m_first->next = next;
	}

	//remove the last element
	void pop_back()
	{
		Node<T>* temp = new Node<T>();
		temp = m_last;
		m_last = nullptr;
		m_last = temp->previous;
	}

	// remove the first element
	void pop_front()
	{
		Node<T>* temp = new Node<T>();
		temp = m_first;
		m_first = nullptr;
		m_first = temp->next;
	}

	// return a Boolean, true if the list is empty, false otherwise
	bool empty() 
	{ 
		if (m_elements == 0)
		{
			return true;
		}
		else
		{
			return false;
		} 
	}
	

	//remove all elements from the list
	void clear()
	{
		Node<T>* temp = m_first;
		// Traverse the list and delete the node one by one from the head 
		while (temp != NULL) {
			// take out the head node 
			m_first = m_first->next;
			delete temp;
			// update the head node 
			temp = m_first;
		}
		// Reset the head and tail node
		m_last = m_first = NULL;
	}

	// remove all elements with matching value
	void remove(T a_value)
	{
		Node<T>* temp = m_first;
		while (temp != m_last)
		{
			if (temp->value == a_value)
			{
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				//temp = nullptr;
			}
			temp = temp->next;
		}
	}
	private:

		//Sentinel nodes
		Node<T>* m_first = nullptr;
		Node<T>* m_last = nullptr;

		int m_elements = 0;
};