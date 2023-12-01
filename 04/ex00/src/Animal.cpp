/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:25:24 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("")
{
	std::cout << BLUE << "Animal default constructor called" << DEFAULT  << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << BLUE << "Animal type constructor called" << DEFAULT  << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << BLUE << "Animal copy constructor called" << DEFAULT  << std::endl;
	*this = src;
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
