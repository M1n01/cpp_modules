/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:03:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/07 21:33:37 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\n====NORMAL TEST====" << std::endl;
	try
	{
		Bureaucrat	king("King", 1);
		std::cout << king << std::endl;

		Bureaucrat	queen("Queen", 2);
		std::cout << queen << std::endl;

		Intern	someRandomIntern;

		std::cout << "\n~~~~SHRUBBERY TEST~~~~" << std::endl;
		AForm	*scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
		std::cout << *scf << std::endl;

		king.signForm(*scf);
		queen.executeForm(*scf);

		std::cout << "\n~~~~ROBOTOMY TEST~~~~" << std::endl;
		AForm	*rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;

		king.signForm(*rrf);
		queen.executeForm(*rrf);

		std::cout << "\n~~~~PRESIDENTIAL TEST~~~~" << std::endl;
		AForm	*ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		king.signForm(*ppf);
		queen.executeForm(*ppf);
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
