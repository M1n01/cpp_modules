/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:47:01 by minabe            #+#    #+#             */
/*   Updated: 2023/10/17 10:05:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::setFirstName(const std::string &first_name)
{
	this->_first_name = first_name;
}

void	Contact::setLastName(const std::string &last_name)
{
	this->_last_name = last_name;
}

void	Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string &phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::setDarkestSecret(const std::string &darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName() const
{
	return (this->_first_name);
}

std::string	Contact::getLastName() const
{
	return (this->_last_name);
}

std::string	Contact::getNickname() const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->_darkest_secret);
}
