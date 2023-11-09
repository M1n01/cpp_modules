/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:13:26 by minabe            #+#    #+#             */
/*   Updated: 2023/11/09 21:26:50 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
