#include "phonebook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "May the contacts be with you" << std::endl;
}

void	PhoneBook::clear(void)
{
	std::cout << "\033[2J";
	std::cout << "\033[H";
	std::cout << "---------------------------------------------\n";
	std::cout << "|       ┌─┐┬ ┬┌─┐┌┐┌┌─┐┌┐ ┌─┐┌─┐┬┌─         |\n";
	std::cout << "|       ├─┘├─┤│ ││││├┤ ├┴┐│ ││ │├┴┐         |\n";
	std::cout << "|       ┴  ┴ ┴└─┘┘└┘└─┘└─┘└─┘└─┘┴ ┴         |\n";
	std::cout << "---------------------------------------------\n";
	std::cin.clear();
}

bool	PhoneBook::add()
{
	std::string	str;
	int	index;

	this->clear();
	if (this->index == 16)
		this->index = 8;
	index = this->index % 8;
	if (this->index > 7)
		std::cout << "Capacity overload! You will override contact[" << index + 1 << "]" << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, str);
		if (this->contacts[index % 8].set_fname(str))
			break ;
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[index % 8].get_fname() << "'s " <<"last name: ";
		std::getline(std::cin, str);
		if (this->contacts[index % 8].set_lname(str))
			break ;
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[index % 8].get_fname() << "'s" <<" nickname: ";
		std::getline(std::cin, str);
		if (this->contacts[index % 8].set_nick(str))
			break ;
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[index % 8].get_fname() << "'s" <<" phone number: ";
		if (std::getline(std::cin, str) && str != "")
			if (this->contacts[index % 8].set_phoneNum(str))
				break ;
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[index % 8].get_fname() << "'s " <<" darkest secret: ";
		std::getline(std::cin, str);
		if (this->contacts[index % 8].set_secret(str))
			break ;
	}
	this->clear();
	this->index++;
	std::cout << "Contact successfuly created [" << index + 1<< "/ 8]" << std::endl;
	return (true);
}

std::string	PhoneBook::add_spaces(int n)
{
	std::string str;

	while (n--)
		str.append(" ");
	return (str);
}

void	PhoneBook::print(int index)
{
	this->clear();
	std::cout << "First name:     ";
	std::cout << this->contacts[index].get_fname() << std::endl;
	std::cout << "Last name:      ";
	std::cout << this->contacts[index].get_lname() << std::endl;
	std::cout << "Nickname:       ";
	std::cout << this->contacts[index].get_nick() << std::endl;
	std::cout << "Phone number:   ";
	std::cout << this->contacts[index].get_phoneNum() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << this->contacts[index].get_secret() << std::endl;
}

void	PhoneBook::fix_input(std::string str)
{
	int	size;
	int	i;

	size = str.size();
	if (size < 10)
		std::cout << this->add_spaces(10 - size) << str;
	else
	{
		i = -1;
		while (++i < 9)
			std::cout << str[i];
		std::cout << ".";
	}
}

bool	PhoneBook::search()
{
	int	i;
	std::string	input;

	this->clear();
	if (this->index == 0)
		return (std::cout << "PhoneBook is empty" << std::endl, true);
	std::cout << "|     index|      name|  lastname|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	i = -1;
	while (++i != 8 && this->contacts[i].get_fname() != "")
	{
		std::cout << "|" << this->add_spaces(9) << i + 1<< "|";
		this->fix_input(this->contacts[i].get_fname());
		std::cout << "|";
		this->fix_input(this->contacts[i].get_lname());
		std::cout << "|";
		this->fix_input(this->contacts[i].get_nick());
		std::cout << "|" << std::endl;
		if (i + 1 != 8 && this->contacts[i + 1].get_fname() != "")
			std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	input = "";
	std::cin.clear();
	while (!std::cin.eof() && input == "")
	{
		std::cout << "Choose an index >>";
		std::getline(std::cin, input);
		if (input.size() == 1 && input[0] >= '1' && input[0] <= '8'
			&& this->contacts[input[0] - 1 - '0'].get_fname() != "")
				this->print(input[0] - 1 - '0');
		else
		{
			input = "";
			std::cout << "Wrong input!" << std::endl;
		}
	}
	return (true);
}