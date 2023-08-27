/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/08/27 17:01:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// index is not used in this program.
void	Phonebook::_add()
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "Please enter the contact you wish to add." << std::endl;
	std::cout << "First name: ";
	std::cin >> first_name;
	_contacts[0]._first_name = first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	_contacts[0]._last_name = last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	_contacts[0]._nickname = nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_number;
	_contacts[0]._phone_number = phone_number;
	std::cout << "darkest_secret: ";
	std::cin >> darkest_secret;
	_contacts[0]._darkest_secret = darkest_secret;
}

void	Phonebook::_search()
{
	std::cout << "|     index|first name| last name|  nickname|phone numb|darkest se|" << std::endl;
	(void)_index;
	for (int i = 0; i < 1; i++)
	{
		std::cout << "|" <<  i << "|" << _contacts[i]._first_name << "|" << _contacts[i]._last_name << "|" << _contacts[i]._nickname << "|" << _contacts[i]._phone_number << "|" << _contacts[i]._darkest_secret << "|" << std::endl;
	}
}

int	main()
{
	Phonebook	phonebook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Please command: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook._add();
		else if (cmd == "SEARCH")
			phonebook._search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "\033 Invalid command. \033" << std::endl;
	}
	return (0);
}
