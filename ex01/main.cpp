#include <string>
#include <iostream>
#include "phonebook.hpp"

int	main()
{
	std::string input;
	PhoneBook	book;

	book.clear();
	while (input != "EXIT" )
	{
		input = "";
		std::cout << "What you gonna do? " << ": ";
		std::getline(std::cin, input);
		if (input.compare("SEARCH") == 0)
			book.search();
		if (input.compare("ADD") == 0)
			book.add();
		if (std::cin.eof())
			return (std::cout << std::endl, 0);
	}
	return (0);
}