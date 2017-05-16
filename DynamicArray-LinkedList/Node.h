#pragma once

template <class T>
struct Node
{
	// Data found in this node
	T m_data;
	//Pointer to next item
	Node* m_Next;
	//Pointer to previous item
	Node* m_Previous;
};
