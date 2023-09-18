/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:02:13 by minabe            #+#    #+#             */
/*   Updated: 2023/09/18 16:21:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::_add(const Contact &contact)
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
