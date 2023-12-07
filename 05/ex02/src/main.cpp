/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 15:03:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;
		RobotomyRequestForm	form("RobotomyRequestForm", "Bender");
		std::cout << form << std::endl;

		Bureaucrat			bender("Bender", 1);
		std::cout << bender << std::endl;

		bender.signForm(form);
		bender.executeForm(form);

		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;
		ShrubberyCreationForm	form2("ShrubberyCreationForm", "Bender");
		std::cout << form2 << std::endl;

		bender.signForm(form2);
		bender.executeForm(form2);

		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;
		PresidentialPardonForm	form3("PresidentialPardonForm", "Bender");
		std::cout << form3 << std::endl;
		bender.signForm(form3);
		bender.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << "\n====SHRUBBERY TEST====" << std::endl;
	try
	{
		RobotomyRequestForm	form("ShrubberyCreationForm", "Bender");

		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex02");
}
