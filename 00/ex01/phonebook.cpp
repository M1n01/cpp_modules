/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/08/27 16:02:28 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	add_contact(Phonebook phonebook)
{
	phonebook._add();
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
		std::cout << "Please command: ";
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
