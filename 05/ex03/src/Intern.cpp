/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:32 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 17:58:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	AForm	*newForm = NULL;

	if (formName == "robotomy request")
		newForm = new RobotomyRequestForm(target);
	else if (formName == "shrubbery creation")
		newForm = new ShrubberyCreationForm(target);
	else if (formName == "presidential pardon")
		newForm = new PresidentialPardonForm(target);
	else
		std::cerr << "Unknown form type: " << formName << std::endl;
	return (newForm);
}
