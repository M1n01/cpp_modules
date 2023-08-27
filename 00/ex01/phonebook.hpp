/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:30 by minabe            #+#    #+#             */
/*   Updated: 2023/08/27 15:48:02 by minabe           ###   ########.fr       */
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
		void		_add(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		void		_search();
	private:
		Contact		_contacts[8];
		int			_index;
};

void	Phonebook::_add(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	_contacts[_index]._first_name = first_name;
	_contacts[_index]._last_name = last_name;
	_contacts[_index]._nickname = nickname;
	_contacts[_index]._phone_number = phone_number;
	_contacts[_index]._darkest_secret = darkest_secret;
}

void	Phonebook::_search()
{
	;
}
