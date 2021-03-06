#include "pch.h"
#include <iostream>

#include "Vector.hpp"

int main()
{
    std::cout << "---------------------------------\n";
	Vector<int> test;
	test.pushBack(1);
	test.pushBack(2);
	test.pushBack(3);
	test.pushBack(4);

	std::cout << test << std::endl;

	std::cout << "pop element -> " << test.popBack() << std::endl;

	std::cout << "size -> " << test.getSize();
	std::cout << "\ncapacity -> " << test.getCapacity() << std::endl;

	std::cout << test << std::endl;

	std::cout << "Erase element at position 0\n";
	test.eraseAt(0);
	std::cout << test;

	std::cout << "\nInsert at 1\n";
	test.insertAt(100, 1);
	std::cout << test << std::endl; 
	std::cout << "size -> " << test.getSize();
	std::cout << "\ncapacity -> " << test.getCapacity() << std::endl;
	return 0;
}
