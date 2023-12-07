/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 10:58:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "exception.hpp"

int	main(void)
{
	Form	form("Form", 42, 42);
	std::cout << form << std::endl;
	Form	hardForm("HardForm", 10, 42);
	std::cout << hardForm << std::endl;

	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		// default constructor
		Bureaucrat	normal("Normal", 42);
		std::cout << normal << std::endl;
		normal.signForm(form);
		std::cout << form << std::endl;
		normal.signForm(hardForm);
		std::cout << hardForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====LOWEST TEST====" << std::endl;
	try
	{
		Bureaucrat	lowest("Lowest", 150);
		std::cout << lowest << std::endl;
		lowest.signForm(hardForm);
		std::cout << hardForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====HIGHEST TEST====" << std::endl;
	try
	{
		Bureaucrat	highest("Highest", 1);
		std::cout << highest << std::endl;
		highest.signForm(hardForm);
		std::cout << hardForm << std::endl;
		highest.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	return (0);
}
