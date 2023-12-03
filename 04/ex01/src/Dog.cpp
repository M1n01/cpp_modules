/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:38 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 14:39:37 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << BLUE << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << BLUE << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*(rhs._brain));
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destructor called" << DEFAULT << std::endl;
	delete this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow!!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
