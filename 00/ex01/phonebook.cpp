/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/09/17 18:04:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::_add(const Contact &contact)
{
	if (_numContacts == MAX_CONTACTS)
	{
		std::cout << "Phonebook is full." << std::endl;
	}
	else
	{
		_contacts[_numContacts] = contact;
		_numContacts++;
	}
}

std::string	format_string(const std::string &str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
		return (str);
}

static void	display_contact_table(Contact &contact, int index)
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format_string(contact._first_name, 10) << "|";
	std::cout << std::setw(10) << format_string(contact._last_name, 10) << "|";
	std::cout << std::setw(10) << format_string(contact._nickname, 10) << "|" << std::endl;
}

void	Phonebook::_search(const std::string name)
{
	for (int i = 0; i < _numContacts; i++)
	{
		if (_contacts[i]._first_name == name || _contacts[i]._last_name == name || _contacts[i]._nickname == name)
		{
			display_contact_table(_contacts[i], i + 1);
			return;
		}
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
