/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:16 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 08:35:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	(void)rhs;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void	ClapTrap::printStatus() const
{
	std::cout << "====" <<  this->_name << "のステータス====" << std::endl;
	std::cout << "[HP]: " << this->_hitPoints << "/" << 10 << std::endl;
	std::cout << "[EP]: " << this->_energyPoints << std::endl;
	std::cout << "[ATK]: " << this->_attackDamage << std::endl << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りず攻撃ができない。』" << std::endl;
	else
	{
		std::cout << "『" << this->_name << "の攻撃！" << target << "は" << this->_attackDamage << "のダメージ!!" << "』" << std::endl;
		this->_energyPoints--;
	}
	printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "『" << this->_name << "は" << amount << "のダメージ!!" << "』" << std::endl;
	if (this->_hitPoints <= amount)
	{
		std::cout << "『" << this->_name << "は力尽きた。』" << std::endl;
		this->_hitPoints = 0;
	}
	else
		this->_hitPoints -= amount;
	printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りない。』" << std::endl;
	else if (this->_hitPoints == 10)
		std::cout << "『" << this->_name << "のHPはすでに満タンだ。』" << std::endl;
	else if (this->_hitPoints + amount > 10)
	{
		std::cout << "『" << this->_name << "は回復した。HPが満タンになった。』" << std::endl;
		this->_hitPoints = 10;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "『" << this->_name << "は" << amount << "回復。" << "』" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	printStatus();
}
