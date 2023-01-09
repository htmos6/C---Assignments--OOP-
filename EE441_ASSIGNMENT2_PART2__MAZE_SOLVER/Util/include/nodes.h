#ifndef NODES_H
#define NODES_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T>* xnode;
};


template <class T> // Given Xor implementation for the linked lists
Node<T>* Xor(Node<T>* x, Node<T>* y) {
	return reinterpret_cast<Node<T>*>(
		reinterpret_cast<uintptr_t>(x)
		^ reinterpret_cast<uintptr_t>(y));
}


template <class T>
void insert(Node<T>*& head_ref, T data) // Given Insert implementation for the linked lists
{
	Node<T>* new_node = new Node<T>();
	new_node->data = data;
	new_node->xnode = head_ref;

	if (head_ref != NULL)
	{
		head_ref->xnode = Xor(new_node, head_ref->xnode);
	}
	head_ref = new_node;
}


template <class T>
void printList(Node<T>* head) { // Given Print List implementation for the linked lists
	Node<T>* currPtr = head;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;

	cout << "The nodes of Linked List are: \n";

	while (currPtr != NULL) {
		cout << currPtr->data;
		nextPtr = Xor(prevPtr, currPtr->xnode);
		prevPtr = currPtr;
		currPtr = nextPtr;
	}
	cout << endl;
}


template <class T>
void push_front(Node<T>*& head_ref, T data) // Use insert inside push front
{
	insert(head_ref, data);
}


template <class T>
void push_rear(Node<T>*& head_ref, T data) // Push rear algorithm is designed for XOR linked list.
{
	Node<T>* head = head_ref;
	Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;

	if (currPtr == NULL)
	{
		push_front(head, data);
	}
	else
	{
		while (currPtr != NULL)
		{
			nextPtr = Xor(prevPtr, currPtr->xnode);
			prevPtr = currPtr;
			currPtr = nextPtr;
		}
		insert(prevPtr, data);
	}
	head_ref = head;
}


template <class T>
Node<T>* pop_front(Node<T>*& head_ref) // Pop front algorithm is designed for XOR linked list.
{
	Node<T>* temp = head_ref;
	Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;

	if (currPtr == NULL)
	{
		return prevPtr;
	}
	else if (currPtr != NULL)
	{
		head_ref = Xor(prevPtr, temp->xnode);
		if (head_ref)
		{
			head_ref->xnode = Xor(prevPtr, Xor(temp, head_ref->xnode));
		}
	}
	delete temp;
	return head_ref;
}


template <class T>
Node<T>* pop_rear(Node<T>*& head_ref) // Pop rear algorithm is designed for XOR linked list.
{
	Node<T>* head = head_ref;
	Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	Node<T>* nullPtr = NULL;

	if (currPtr == NULL)
	{
		return prevPtr;
	}
	else if (currPtr != NULL)
	{
		while (Xor(currPtr->xnode, prevPtr))
		{
			nextPtr = Xor(prevPtr, currPtr->xnode);
			prevPtr = currPtr;
			currPtr = nextPtr;
		}
		if (prevPtr)
		{
			prevPtr->xnode = Xor(Xor(prevPtr->xnode, currPtr), nullPtr);
		}
		else
		{
			head_ref = nullPtr;
		}
		delete currPtr;
	}
	return head_ref;
}


template <class T>
Node<T>* peek_front(Node<T>*& head_ref) // Peek front algorithm is designed for XOR linked list.
{
	Node<T>* head = head_ref;
	Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	Node<T>* nullPtr = NULL;

	if (currPtr == NULL)
	{
		return prevPtr;
	}
	else
	{
		return head_ref;
	}
}

#endif // NODE_H



