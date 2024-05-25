#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>
#include <iostream>

class	Contact
{
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	nick;
		std::string	phone_num;
		std::string	secret;
	public:
		Contact(void);
		std::string	get_fname(void);
		std::string	get_lname(void);
		std::string	get_nick(void);
		std::string	get_phoneNum(void);
		std::string	get_secret(void);
		bool	set_fname(std::string str);
		bool	set_lname(std::string str);
		bool	set_nick(std::string str);
		bool	set_phoneNum(std::string str);
		bool	set_secret(std::string str);
};

#endif