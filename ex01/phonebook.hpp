#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contacts.hpp"
#include <iostream>

class	PhoneBook
{
	private :
		Contact	contacts[8];
		int		index;
		std::string	add_spaces(int n);
		void	print(int index);
		void	fix_input(std::string str);
	public :
		PhoneBook(void);
		~PhoneBook(void);
		void	clear(void);
		bool	add(void);
		bool	search(void);
};

#endif