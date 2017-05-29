#pragma once
//Create a template class for storing any data-type. 
//The data itself should be stored as a private pointer 
//to an array on the heap.

template <class T>
class Storage
{
public:
	//1. Constructor DESCRIPTION: Creates an array on the heap of the specified capacity.
	//The new heap memory should be zeroed using memset. 
	//You should store the value of capacity and size for later use (size should start at 0). 
	//INPUT: A single integer specifying the capacity for the data array. 
	//OUTPUT: N/A.
	Storage<T>(const int& a_iCapacity)
	{
		m_iCapacity = a_iCapacity;
		m_data = new T[m_iCapacity] { 0 };
		m_iSize = 0;
	}
	//2. Deconstructor 
    //DESCRIPTION: Deletes the data pointed to on the heap. 
    //INPUT: N/A. 
    //OUTPUT: N/A.
	~Storage<T>()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	//3. Add DESCRIPTION: 
	//Adds an item to the next empty array location 
	//(you should be able to use the size value as an index to the next free location). 
	//Before adding the new item to the array, we should check if there is room and call Expand if not. 
	//INPUT: One template arguments (item). 
	//OUTPUT: None.
	template <class T>
	void Add(const T& a_item)
	{
		if (m_iSize == m_iCapacity)
		{
			Expand();
		}
		m_data[m_iSize] = a_item;
		m_iSize++;
	}

	

	//5. Operator [] DESCRIPTION: 
	//Returns an item from the array at a specified index (like a regular subscript). 
	//INPUT: A single integer specifying the array-index of the item to return. 
	//OUTPUT: A copy/reference (your choice) of an item from the data array.
	T& operator[](const int& a_iIndex)
	{
		return m_data[a_iIndex];
	}
	int m_iSize;
private:
	//4. Expand DESCRIPTION: 
	//Doubles the capacity of the data array 
	//by creating a new array on the heap with twice the current capacity, 
	//and then copying the data from the current array 
	//into the new array using memcpy. 
	//(Be sure to delete the old memory!) 
	//INPUT: None. 
	//OUTPUT: None.

	void Expand()
	{
		m_iCapacity *= 2;
		T* newStorage = new T[m_iCapacity]{ 0 };
		for (int i = 0; i < m_iSize; ++i)
		{
			newStorage[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newStorage;
		newStorage = nullptr;
	}

	T* m_data;
	int m_iCapacity;
};

