/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:38:33 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 14:08:59 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "exception.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	protected:
		std::string const	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat	&operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &rhs);
