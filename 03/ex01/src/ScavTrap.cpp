/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:16:56 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 22:57:40 by minabe           ###   ########.fr       */
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

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else
		std::cout << "『" << this->_name << "はGate keeper modeに入った。』" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りず攻撃ができない。』" << std::endl;
	else
	{
		std::cout << "『" << this->_name << "は不思議な踊りをした。" << target << "は" << this->_attackDamage << "のダメージ!!" << "』" << std::endl;
		this->_energyPoints--;
	}
	printStatus();
}
