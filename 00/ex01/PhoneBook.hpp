/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:30 by minabe            #+#    #+#             */
/*   Updated: 2023/10/25 14:28:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <sstream>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_numContacts;
	public:
		PhoneBook(void);
		void	addContact(const Contact &contact);
		bool	searchContacts();
		int		getNumContacts() const;
		Contact	getContact(int index) const;
};
