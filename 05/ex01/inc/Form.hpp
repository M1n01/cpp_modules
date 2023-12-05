/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:36:37 by minabe            #+#    #+#             */
/*   Updated: 2023/12/05 18:13:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "exception.hpp"
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(std::string const &name, unsigned int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		Form	&operator=(Form const &rhs);
		~Form(void);

		const std::string	getName(void) const;
		bool				beSigned(Bureaucrat const &bureaucrat);
};

std::ostream	&operator<<(std::ostream& os, const Form& form);
