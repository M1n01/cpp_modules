/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/08/27 15:48:40 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	add_contact(Phonebook phonebook)
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	std::cin >> first_name >> last_name >> nickname >> phone_number >> darkest_secret;
	phonebook._add(first_name, last_name, nickname, phone_number, darkest_secret);
}

void	search_contact(Phonebook phonebook)
{
	phonebook._search();
}

int	main()
{
	Phonebook	phonebook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Please " << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			add_contact(phonebook);
		else if (cmd == "SEARCH")
			search_contact(phonebook);
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
