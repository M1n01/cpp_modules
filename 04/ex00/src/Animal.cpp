/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:05:08 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 22:47:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Animal.hpp"

Animal::Animal(void) {}

Animal::Animal(std::string type) : _type(type) {}

Animal::~Animal(void) {}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
