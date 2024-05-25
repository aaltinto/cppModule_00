#include "contacts.hpp"
#include <iostream>
#include <string>

Contact::Contact(void)
{
	this->f_name = "";
	this->l_name = "";
	this->nick = "";
	this->phone_num = "";
	this->secret = "";
}

std::string	Contact::get_fname(void)
{
	return (this->f_name);
}

std::string Contact::get_lname(void)
{
	return (this->l_name);
}

std::string Contact::get_nick(void)
{
	return (this->nick);
}

std::string Contact::get_phoneNum(void)
{
	return (this->phone_num);
}

std::string Contact::get_secret(void)
{
	return (this->secret);
}

bool	Contact::set_fname(std::string str)
{
	if (str.empty())
	{
		std::cout << "First name can not be left empty" << std::endl;
		return (false);
	}
	this->f_name = str;
	return (true);
}

bool	Contact::set_lname(std::string str)
{
	if (str.empty())
	{
		std::cout << "Last name can not be left empty" << std::endl;
		return (false);
	}
	this->l_name = str;
	return (true);
}

bool	Contact::set_nick(std::string str)
{
	if (str.empty())
	{
		std::cout << "Nick can not be left empty" << std::endl;
		return (false);
	}
	this->nick = str;
	return (true);
}

bool	Contact::set_phoneNum(std::string str)
{
	if (str.empty())
	{
		std::cout << "Phone number can not be left empty" << std::endl;
		return (false);
	}

	this->phone_num = str;
	return (true);
}

bool	Contact::set_secret(std::string str)
{
	if (str.empty())
	{
		std::cout << "Phone number can not be left empty" << std::endl;
		return (false);
	}
	this->secret = str;
	return (true);
}