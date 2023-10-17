/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:30 by minabe            #+#    #+#             */
/*   Updated: 2023/10/17 09:57:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_numContacts;
	public:
		PhoneBook() : _numContacts(0) {};
		void	_add(const Contact &contact);
		void	_search();
};
