/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:01:13 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:33:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(void): _name("") {}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << RED << this->_name << " is destroyed for debugging." << DEFAULT << std::endl;
}

void	Zombie::announce(void)
{
	std::cout  << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
