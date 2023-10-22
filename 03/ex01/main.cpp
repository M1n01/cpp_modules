/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/10/22 16:54:09 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scavTrap("勇者");

	scavTrap.attack("うごくせきぞう");
	scavTrap.takeDamage(10);
	scavTrap.guardGate();

	scavTrap.attack("キラーマシン");
	scavTrap.takeDamage(100);
	scavTrap.beRepaired(REPAIR);
	scavTrap.guardGate();
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex01");
}
