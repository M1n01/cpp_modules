/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:44:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << BLUE << "Cat default constructor called" << DEFAULT  << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << BLUE << "Cat type constructor called" << DEFAULT  << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << BLUE << "Cat copy constructor called" << DEFAULT  << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << BLUE << "Cat assignation operator called" << DEFAULT  << std::endl;
	(void)rhs;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << YELLOW << "Cat destructor called" << DEFAULT << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "(Cats don’t bark)" << std::endl;
}
