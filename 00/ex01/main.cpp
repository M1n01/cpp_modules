/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:14:07 by minabe            #+#    #+#             */
/*   Updated: 2023/10/17 10:14:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	cmdLoop(PhoneBook &phoneBook);
static void	inputContact(Contact &contact);

int	main()
{
	PhoneBook	phoneBook;

	cmdLoop(phoneBook);
	return (0);
}

static void	cmdLoop(PhoneBook &phoneBook)
{
	std::string	cmd;
	Contact		contact;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			inputContact(contact);
			phoneBook._add(contact);
		}
		else if (cmd == "SEARCH")
			phoneBook._search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
}

static void	inputContact(Contact &contact)
{
	std::string	input;

	std::cout << "Enter a first name: ";
	std::cin >> input;
	contact.setFirstName(input);
	std::cout << "Enter a last name: ";
	std::cin >> input;
	contact.setLastName(input);
	std::cout << "Enter a nickname: ";
	std::cin >> input;
	contact.setNickname(input);
	std::cout << "Enter a phone number: ";
	std::cin >> input;
	contact.setPhoneNumber(input);
	std::cout << "Enter a darkest secret: ";
	std::cin >> input;
	contact.setDarkestSecret(input);
}
