/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/09/18 15:03:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	cmd_loop(Phonebook &phonebook)
{
	std::string	cmd;
	Contact		contact;

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
			phonebook._search();
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
