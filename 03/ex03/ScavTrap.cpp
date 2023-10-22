/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:16:56 by minabe            #+#    #+#             */
/*   Updated: 2023/10/22 17:04:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
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
