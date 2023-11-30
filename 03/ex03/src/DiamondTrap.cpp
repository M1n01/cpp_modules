/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:31:52 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 12:18:47 by minabe           ###   ########.fr       */
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
