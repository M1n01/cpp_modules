/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:14:07 by minabe            #+#    #+#             */
/*   Updated: 2023/10/17 14:57:02 by minabe           ###   ########.fr       */
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
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			inputContact(contact);
			phoneBook._add(contact);
		}
		else if (cmd == "SEARCH")
		{
			outputPhoneBook(phoneBook);
			phoneBook._search();
		}
		else if (cmd == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}

static void	inputContact(Contact &contact)
{
	std::string	input;

	std::cout << "Enter a first name: ";
	getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "Enter a last name: ";
	getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "Enter a nickname: ";
	getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "Enter a phone number: ";
	getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "Enter a darkest secret: ";
	getline(std::cin, input);
	contact.setDarkestSecret(input);
}

static std::string	format_string(const std::string &str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
		return (str);
}

static void	displaRow(const Contact &contact, int index)
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
		displaRow(phoneBook.getContact(i), i + 1);
}
