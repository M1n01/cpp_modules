/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:38 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 12:53:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << BLUE << "Dog default constructor called" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << BLUE << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << YELLOW << "Dog destructor called" << DEFAULT << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
