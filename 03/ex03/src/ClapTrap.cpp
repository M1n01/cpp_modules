/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:16 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:58:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(HP), _energyPoints(EP), _attackDamage(ATK)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(HP), _energyPoints(EP), _attackDamage(ATK)
{
	std::cout << "ClapTrap constructor called." << std::endl;
	this->_name = name;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &dummy)
{
	(void)dummy;
	return (*this);
}

static void	printStatus(const std::string& name, int hitPoints, int energyPoints, int attackDamage)
{
	std::cout << "====" <<  name << "のステータス====" << std::endl;
	std::cout << "[HP]: " << hitPoints << "/" << HP << std::endl;
	std::cout << "[EP]: " << energyPoints << std::endl;
	std::cout << "[ATK]: " << attackDamage << std::endl << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りず攻撃ができない。』" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "『" << this->_name << "の攻撃！" << target << "は" << this->_attackDamage << "のダメージ!!" << "』" << std::endl;
	}
	printStatus(this->_name, this->_hitPoints, this->_energyPoints, this->_attackDamage);
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
	printStatus(this->_name, this->_hitPoints, this->_energyPoints, this->_attackDamage);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は気絶している。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りない。』" << std::endl;
	else if (this->_hitPoints == HP)
		std::cout << "『" << this->_name << "のHPはすでに満タンだ。』" << std::endl;
	else if (this->_hitPoints + amount > HP)
	{
		std::cout << "『" << this->_name << "は回復した。HPが満タンになった。』" << std::endl;
		this->_hitPoints = HP;
	}
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "『" << this->_name << "は" << amount << "回復。" << "』" << std::endl;
	}
	printStatus(this->_name, this->_hitPoints, this->_energyPoints, this->_attackDamage);
}
