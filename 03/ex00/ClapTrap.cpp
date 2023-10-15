/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:16 by minabe            #+#    #+#             */
/*   Updated: 2023/10/15 18:48:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called." << std::endl;
	this->_name = name;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void	attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void	beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " is repaired " << amount << " points!" << std::endl;
}
