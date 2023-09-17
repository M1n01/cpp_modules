/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/09/17 16:32:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::_add(const Contact &contact)
{
	if (_contacts.size() == 8)
		_contacts.pop();
	_contacts.push(contact);
}

void	Phonebook::_search(const std::string name)
{
	std::queue<Contact>	temp;

	temp = _contacts;
	while (!temp.empty())
	{
		const Contact& entry = temp.front();

		if (entry._first_name == name || entry._last_name == name)
		{
			std::cout << "Phone: " << entry._phone_number << std::endl;
			return ;
		}
		temp.pop();
	}
	std::cout << "Name not found!" << std::endl;
}

static void	cmd_loop(Phonebook &phonebook)
{
	std::string	cmd;
	Contact		contact;
	std::string	name;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			std::cout << "First name: ";
			std::cin >> contact._first_name;
			std::cout << "Last name: ";
			std::cin >> contact._last_name;
			std::cout << "Nickname: ";
			std::cin >> contact._nickname;
			std::cout << "Phone number: ";
			std::cin >> contact._phone_number;
			std::cout << "Dardest secret: ";
			std::cin >> contact._darkest_secret;
			phonebook._add(contact);
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "Enter a name: ";
			std::cin >> name;
			phonebook._search(name);
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}

int	main()
{
	Phonebook	phonebook;

	cmd_loop(phonebook);
	return (0);
}
