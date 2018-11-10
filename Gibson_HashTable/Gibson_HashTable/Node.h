//Denzell Gibson
//6/25/2017

#ifndef NODE_H_
#define NODE_H_

#include "Header.h"

template <class T>
class Node
{
public:
	Node(); //Default constructor.
	Node(std::string, T); //Constructors that takes a string and T variables as parameters.

	//Setter and Getter methods.
	void setKey(std::string);
	void setData(T);
	void setNext(Node<T>*);
	std::string getKey();
	T getData();
	Node<T>* getNext();

private:
	//Declarations.
	std::string key;
	T data;
	Node<T>* next; //Pointer that points to the next Node.
};

//Default constructor.
template <class T>
Node<T>::Node()
{
	//Sets values.
	key = " ";
	data = 0;
	next = NULL;
}

//Constructor that initializes variables with passed in values.
template <class T>
Node<T>::Node(std::string newKey, T newData)
{
	key = newKey;
	data = newData;
	next = NULL;
}

//Setter for key variable.
template <class T>
void Node<T>::setKey(std::string newKey)
{
	key = newKey;
}

//Setter for data variable.
template <class T>
void Node<T>::setData(T newData)
{
	data = newData;
}

//Setter for next pointer.
template <class T>
void Node<T>::setNext(Node<T>* newNext)
{
	next = newNext;
}

//Getter for key variable.
template <class T>
std::string Node<T>::getKey()
{
	return key;
}

//Getter for data variable.
template <class T>
T Node<T>::getData()
{
	return data;
}

//Getter for next pointer.
template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

#endif
