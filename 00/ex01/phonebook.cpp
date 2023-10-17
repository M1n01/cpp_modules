/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:32 by minabe            #+#    #+#             */
/*   Updated: 2023/10/17 14:20:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::_add(const Contact &contact)
{
	if (_numContacts == MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[MAX_CONTACTS - 1] = contact;
	}
	else
	{
		_contacts[_numContacts] = contact;
		_numContacts++;
	}
}

static void	outputContact(Contact &contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::_search()
{
	int			index;

	std::cout << "Enter an index: ";
	std::cin >> index;
	if (std::cin.fail() || (index < 1 || _numContacts < index))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	outputContact(_contacts[index - 1]);
}

int	PhoneBook::getNumContacts() const
{
	return (_numContacts);
}

Contact	PhoneBook::getContact(int index) const
{
	return (_contacts[index]);
}
