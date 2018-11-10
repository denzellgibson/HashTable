//Denzell Gibson
//6/29/2017

#include "Header.h"
#include "HashTable.h"

void AutomaticTesting();

int main()
{
	AutomaticTesting();

	system("pause");
	return 0;
}

void AutomaticTesting()
{
	std::cout << "***Test Hash Table Constructor***" << std::endl;
	HashTable<int> table;
	if (table.getSize() > 0)
		std::cout << "PASSED - Hash Table created and empty." << std::endl;
	else
		std::cout << "FAILED - Hash Table has not been created." << std::endl;

	std::cout << "***Testing Retrieve function when table is empty***" << std::endl;
	if (table.retrieve("John") == NULL)
		std::cout << "PASSED - Null is returned." << std::endl;
	else
		std::cout << "FAILED - Another value besides NULL was returned." << std::endl;

	std::cout << "***Testing insert function***" << std::endl;
	table.insert("John", 123);
	if (table.retrieve("John") == 123)
		std::cout << "PASSED - Insertion of key and data was successful." << std::endl;
	else
		std::cout << "FAILED - Node containing key and data was not found." << std::endl;

	std::cout << "***Testing multiple insertion of keys and data***" << std::endl;
	table.insert("Robert", 456);
	table.insert("Miyazaki", 789);
	table.insert("Kyle", 741);
	table.insert("Denzell", 852);
	table.insert("Cirey", 963);
	table.insert("Kobayashi", 753);
	table.insert("Alphonso", 159);
	if (table.retrieve("Robert") == 456 && table.retrieve("Alphonso") == 159)
		std::cout << "PASSED - All nodes successfully inserted and found." << std::endl;
	else
		std::cout << "FAILED - Some or all nodes are missing." << std::endl;
}