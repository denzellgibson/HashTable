//Denzell Gibson
//6/25/2017

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Header.h"
#include "Node.h"

template <class T>
class LinkedList
{
public:
	LinkedList(); //Default constructor.

	void insert(std::string, T); //Creates a new node and puts it at the end of the list.
	Node<T>* find(std::string); //Finds the Node with the matching key and returns the pointer.

private:
	Node<T>* head; //Intended to point to the first Node in the list.
	Node<T>* tail; //Intended to point to the last Node in the list.
};

//Creates a new LinkedList. 
template <class T>
LinkedList<T>::LinkedList()
{
	//Sets head and tail to NULL.
	head = NULL;
	tail = NULL;
}

//Takes an int argument and creates a new Node.
template <class T>
void LinkedList<T>::insert(std::string newKey, T newData)
{
	if (head == NULL) //If the list is empty...
	{
		head = new Node<T>(newKey, newData); //The new Node will be assigned to the 'head' Node pointer.
		tail = head; //The 'tail' Node pointer to the new Node as well.
	}
	else //Otherwise, if the list isn't empty...
	{
		tail->setNext(new Node<T>(newKey, newData)); //Creates a new Node after the tail Node.
		tail = tail->getNext(); //Sets the tail to the newly created Node.
	}
}

//Finds a node by matching the value passed in with the data member of the Node.
template <class T>
Node<T>* LinkedList<T>::find(std::string key)
{
	Node<T>* currentNode; //Creates a new Node pointer called currentNode (will be referred to by 'current').
	currentNode = head; //Assigns the first Node to 'current' Node pointer.

	while (currentNode != NULL) //While the 'current' Node pointer is not NULL...
	{
		if (currentNode->getKey() == key) //If the data member 'data' is equal to the passed in value 'number'...
		{
			return currentNode; //Return the 'current' Node pointer.
			break; //Breaks from the loop, ending the function.
		}
		else //Otherwise, if the two values are not equal...
		{
			currentNode = currentNode->getNext(); //Assign the next Node in the list to the 'current' Node pointer.
		}
	}
	return NULL;
}

#endif