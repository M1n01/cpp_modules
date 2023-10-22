/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/10/22 18:02:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scavTrap("勇者");

	scavTrap.attack("うごくせきぞう");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(REPAIR);
	scavTrap.guardGate();

	scavTrap.attack("キラーマシン");
	scavTrap.takeDamage(99);
	scavTrap.beRepaired(REPAIR);
	scavTrap.guardGate();

	scavTrap.attack("ゲマ");
	scavTrap.takeDamage(100000000);
	scavTrap.beRepaired(REPAIR);

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex01");
}
