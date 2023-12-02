/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:08:25 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 13:04:40 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap("FlagTrap")
{
	std::cout << "FlagTrap default constructor called." << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	std::cout << "FlagTrap constructor called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FlagTrap	&FlagTrap::operator=(const FlagTrap &rhs)
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

FlagTrap::~FlagTrap(void)
{
	std::cout << "FlagTrap destructor called." << std::endl;
}

void	FlagTrap::highFivesGuys(void)
{
	if (this->_hitPoints < 1)
		std::cout << "『" << this->_name << "は瀕死状態だ。』" << std::endl;
	else
		std::cout << "『" << this->_name << "は、ハイタッチしたそうにしている。』" << std::endl;
}
