/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 20:02:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << BLUE << "Animal default constructor called" << DEFAULT  << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << BLUE << "Animal type constructor called" << DEFAULT  << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	(void)rhs;
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
	std::cout << RED << "<Animal sound>" << DEFAULT << std::endl;
}
