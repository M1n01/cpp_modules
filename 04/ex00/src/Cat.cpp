/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:15:29 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 12:53:55 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << BLUE << "Cat default constructor called" << DEFAULT  << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << BLUE << "Cat copy constructor called" << DEFAULT  << std::endl;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat destructor called" << DEFAULT << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "(Cats don’t bark)" << std::endl;
}
