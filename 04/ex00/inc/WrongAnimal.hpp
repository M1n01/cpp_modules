/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:42:30 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 19:46:59 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal	&operator=(const WrongAnimal &rhs);
		virtual ~WrongAnimal();

		std::string	getType() const;
		void		makeSound() const;
};
