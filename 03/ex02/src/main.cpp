/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:57:55 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FlagTrap.hpp"

int	main(void)
{
	FlagTrap	flagTrap("勇者");

	flagTrap.attack("うごくせきぞう");
	flagTrap.takeDamage(10);
	flagTrap.beRepaired(REPAIR);
	flagTrap.highFivesGuys();

	flagTrap.attack("キラーマシン");
	flagTrap.takeDamage(99);
	flagTrap.beRepaired(REPAIR);
	flagTrap.highFivesGuys();

	flagTrap.attack("ゲマ");
	flagTrap.takeDamage(100000000);
	flagTrap.beRepaired(REPAIR);

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex02");
}
