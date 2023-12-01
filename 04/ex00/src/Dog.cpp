/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:44:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << BLUE << "Dog type constructor called" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << BLUE << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << BLUE << "Dog assignation operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destructor called" << DEFAULT << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
