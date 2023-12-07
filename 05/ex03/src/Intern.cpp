/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:32 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 16:58:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return (*this);
}

Intern::~Intern(void) {}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target)
{
	if (formName == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (formName == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else if (formName == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
		throw UnknownFormException();
}
