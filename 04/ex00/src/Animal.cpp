/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 09:22:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cout << BLUE << "Animal default constructor called" << DEFAULT  << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << BLUE << "Animal copy constructor called" << DEFAULT  << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << YELLOW << "Animal destructor called" << DEFAULT << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << RED << "<Animal Sound>" << DEFAULT << std::endl;
}
