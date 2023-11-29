/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:16:56 by minabe            #+#    #+#             */
/*   Updated: 2023/11/29 23:00:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
		return ;
	}
	std::cout << "『" << _name << " Gate keeper modeに入った。』" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
		return ;
	}
	std::cout << "『" << this->_name << "は" << target << "を攻撃した。』" << std::endl;
}
