/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:46:21 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 09:22:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << YELLOW << "WrongCat default constructor called." << DEFAULT << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << YELLOW << "WrongCat copy constructor called." << DEFAULT << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << YELLOW << "WrongCat assignation operator called." << DEFAULT << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat destructor called." << DEFAULT << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << RED << "Meow Meow" << DEFAULT << std::endl;
}
