/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:31:52 by minabe            #+#    #+#             */
/*   Updated: 2023/10/22 21:38:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FlagTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FlagTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
