/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:01:13 by minabe            #+#    #+#             */
/*   Updated: 2023/10/07 15:44:00 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): _name("") {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is destroyed for debugging." << std::endl;
}

void	Zombie::_announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}