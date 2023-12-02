/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 09:24:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << BLUE << "AAnimal default constructor called" << DEFAULT  << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << BLUE << "AAnimal copy constructor called" << DEFAULT  << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << YELLOW << "AAnimal destructor called" << DEFAULT << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
