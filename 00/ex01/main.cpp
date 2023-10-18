/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:14:07 by minabe            #+#    #+#             */
/*   Updated: 2023/10/18 15:17:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

static void	cmdLoop(PhoneBook &phoneBook);
static void	inputContact(Contact &contact);
static void	outputPhoneBook(PhoneBook &phoneBook);

int	main(void)
{
	PhoneBook	phoneBook;

	cmdLoop(phoneBook);
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q phoneBook");
}

static void	cmdLoop(PhoneBook &phoneBook)
{
	std::string	cmd;
	Contact		contact;

	while (true)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, cmd) || std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		if (cmd == "ADD")
		{
			inputContact(contact);
			phoneBook.addContact(contact);
		}
		else if (cmd == "SEARCH")
		{
			outputPhoneBook(phoneBook);
			phoneBook.searchContacts();
			if (std::cin.eof())
				break ;
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}

static void	inputContact(Contact &contact)
{
	std::string	input;

	std::cout << "======= Enter Contact =======\n";
	std::cout << "[First name] => ";
	getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "[Last name] => ";
	getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "[Nickname] => ";
	getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "[Phone number] => ";
	getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "[Darkest secret] => ";
	getline(std::cin, input);
	contact.setDarkestSecret(input);
	std::cout << "=============================\n";
}

static std::string	format_string(const std::string &str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
		return (str);
}

static void	displayRow(const Contact &contact, int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format_string(contact.getFirstName(), 10) << "|";
	std::cout << std::setw(10) << format_string(contact.getLastName(), 10) << "|";
	std::cout << std::setw(10) << format_string(contact.getNickname(), 10) << "|" << std::endl;
}

static void	outputPhoneBook(PhoneBook &phoneBook)
{
	std::string	header;

	header = "|Index     |First name|Last name |Nickname  |";
	std::cout << header << std::endl;
	for (int i = 0; i < phoneBook.getNumContacts(); i++)
		displayRow(phoneBook.getContact(i), i + 1);
}