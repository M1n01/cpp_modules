/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:31:52 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 23:02:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FlagTrap()
{
	this->_name = "DiamondTrap";
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FlagTrap(name)
{
	this->_name = name;
	std::cout << "DiamondTrap constructor called for " << name << "." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else
	{
		std::cout << "『ClapTrap 私は " << ClapTrap::_name << " だ。』" << std::endl;
		std::cout << "『私は " << _name << " だ。』" << std::endl;
	}
}
