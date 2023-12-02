/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:16 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 14:47:31 by minabe           ###   ########.fr       */
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
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "====" <<  this->_name << "のステータス====" << std::endl;
	std::cout << "[HP]: " << this->_hitPoints << "/" << HP_MAX << std::endl;
	std::cout << "[EP]: " << this->_energyPoints << std::endl;
	std::cout << "[ATK]: " << this->_attackDamage << std::endl << std::endl;
}

bool	ClapTrap::canAttack(void) const
{
	if (this->_hitPoints < 1)
	{
		std::cout << "『" << this->_name << "は瀕死状態だ。』" << std::endl;
		return (false);
	}
	else if (this->_energyPoints < 1)
	{
		std::cout << "『" << this->_name << "はEPが足りず攻撃ができない。』" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->canAttack())
	{
		std::cout << "『" << this->_name << "は、たいあたりを繰り出した！" << target << "は" << this->_attackDamage << "のダメージ!!" << "』" << std::endl;
		this->_energyPoints--;
	}
	printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "『" << this->_name << "は、たいあたりをくらった。" << amount << "のダメージ!!" << "』" << std::endl;
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
		std::cout << "『傷薬を使えなかった。" << this->_name << "は瀕死状態だ。』" << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << "『" << this->_name << "はEPが足りない。』" << std::endl;
	else if (this->_hitPoints == HP_MAX)
		std::cout << "『傷薬を使えなかった。" << this->_name << "のHPはすでに満タンだ。』" << std::endl;
	else if (this->_hitPoints + amount > HP_MAX)
	{
		std::cout << "『傷薬を使った。" << this->_name << "は回復した。HPが満タンになった。』" << std::endl;
		this->_hitPoints = HP_MAX;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "『傷薬を使った。" << this->_name << "は" << amount << "回復。" << "』" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	printStatus();
}
