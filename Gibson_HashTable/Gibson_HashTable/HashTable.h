//Denzell Gibson
//6/25/2017

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Header.h"
#include "Node.h"
#include "LinkedList.h"

template <class T>
class HashTable
{
public:
	HashTable(); //Default constructor.
	HashTable(int); //Constructor that allows the setting the size of the table.

	void insert(std::string, T); //Inserts a new Node into the appropriate LinkedList.
	T retrieve(std::string); //Returns data value.

	int getSize();

private:
	//Declarations.
	std::vector<LinkedList<T>*> tree;
	//LinkedList<T>* table[13]; //Array of LinkedList pointers.
	int size;

	int hashFunction(std::string);
};

//Default constructor.
template <class T>
HashTable<T>::HashTable()
{
	size = 13;

	for (int i = 0; i < size; i++)
	{
		tree.push_back(new LinkedList<T>());
	}

	/*for (int i = 0; i < sizeof(table)/sizeof(table[0]); i++)
	{
		table[i] = new LinkedList<T>();
	}*/

}

//Constructor that allows to set the size of table.
template <class T>
HashTable<T>::HashTable(int newSize)
{
	size = newSize;
	for (int i = 0; i < size; i++)
	{
		tree.push_back(new LinkedList<T>());
	}
}

//Creates a number from the number of characters in the key.
template <class T>
int HashTable<T>::hashFunction(std::string key)
{
	int number = 0;

	for (int i = 0; i < key.size(); i++)
	{
		number += i;
	}
	number *= 100;
	number %= size;
	return number;
}

//Inserts a new key and the associated data into the HashTable.
template <class T>
void HashTable<T>::insert(std::string newKey, T newData)
{
	int number;
	number = hashFunction(newKey);
	tree[number]->insert(newKey, newData);
	//table[number]->insert(newKey, newData);
}

//Returns the data that is associated with the key.
template <class T>
T HashTable<T>::retrieve(std::string key)
{
	T data = NULL;
	int number;
	Node<T>* retrieval;
	number = hashFunction(key);
	//retrieval = table[number]->find(key);
	retrieval = tree[number]->find(key);
	if (retrieval == NULL)
			return 0;
	else
		return retrieval->getData();
}

template <class T>
int HashTable<T>::getSize()
{
	return size;
}

#endif