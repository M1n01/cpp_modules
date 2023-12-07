/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:33 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 10:23:10 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, unsigned int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(Form const &src)
	: _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

Form::~Form(void) {}

const std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
	{
		_signed = true;
		return (true);
	}
}

std::ostream	&operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << ", Signed: " << (form.getSigned() ? "true" : "false");
	return (os);
}
