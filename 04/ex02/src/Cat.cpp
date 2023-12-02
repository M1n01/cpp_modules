/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 15:47:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << BLUE << "Cat default constructor called" << DEFAULT  << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src), _brain(new Brain(*src._brain))
{
	std::cout << BLUE << "Cat copy constructor called" << DEFAULT  << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << BLUE << "Cat assignation operator called" << DEFAULT  << std::endl;
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*(rhs._brain));
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << YELLOW << "Cat destructor called" << DEFAULT << std::endl;
	delete this->_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "(Cats don’t bark)" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
