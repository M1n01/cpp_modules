/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:34 by minabe            #+#    #+#             */
/*   Updated: 2023/09/18 16:27:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string	format_string(const std::string &str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
		return (str);
}

static void	display_row(Contact &contact, int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format_string(contact._first_name, 10) << "|";
	std::cout << std::setw(10) << format_string(contact._last_name, 10) << "|";
	std::cout << std::setw(10) << format_string(contact._nickname, 10) << "|" << std::endl;
}

void Phonebook::_search()
{
	int			index;
	std::string	header;

	header = "|Index     |First name|Last name |Nickname  |";
	std::cout << header << std::endl;
	for (int i = 0; i < _numContacts; i++)
		display_row(_contacts[i], i + 1);
	std::cout << "Enter an index: ";
	std::cin >> index;
	if (std::cin.fail() || index < 1 || _numContacts < index)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	std::cout << header << std::endl;
	for (int i = 0; i < _numContacts; i++)
	{
		if (i == index - 1)
		{
			display_row(_contacts[i], i + 1);
			return ;
		}
	}
	std::cout << "Invalid index!" << std::endl;
}
