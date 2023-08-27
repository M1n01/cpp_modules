/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:30 by minabe            #+#    #+#             */
/*   Updated: 2023/08/27 16:39:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Contact
{
	public:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

class Phonebook {
	public:
		void		_add();
		void		_search();
	private:
		Contact		_contacts[8];
		// int			_index;
};

void	Phonebook::_add()
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "Please enter the contact you wish to add." << std::endl;
	std::cout << "First name: ";
	std::cin >> first_name;
	_contacts[0]._first_name = first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	_contacts[0]._last_name = last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	_contacts[0]._nickname = nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_number;
	_contacts[0]._phone_number = phone_number;
	std::cout << "darkest_secret: ";
	std::cin >> darkest_secret;
	_contacts[0]._darkest_secret = darkest_secret;
}

void	Phonebook::_search()
{
	;
}
