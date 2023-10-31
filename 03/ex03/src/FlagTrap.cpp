/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:08:25 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:59:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap("FlagTrap")
{
	std::cout << "FlagTrap default constructor called." << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	std::cout << "FlagTrap constructor called." << std::endl;
	this->_name = name;
	this->_hitPoints = HP;
	this->_energyPoints = EP;
	this->_attackDamage = ATK;
}

FlagTrap::~FlagTrap(void)
{
	std::cout << "FlagTrap destructor called." << std::endl;
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "『" << this->_name << "はハイタッチしたそうにしている。』" << std::endl;
}
