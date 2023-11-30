/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 17:05:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	// DiamondTrap	diamondTrap("勇者");
	DiamondTrap	diamondTrap;

	diamondTrap.attack("うごくせきぞう");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	diamondTrap.attack("キラーマシン");
	diamondTrap.takeDamage(99);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	diamondTrap.attack("ゲマ");
	diamondTrap.takeDamage(100000000);
	diamondTrap.beRepaired(100);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex03");
}
