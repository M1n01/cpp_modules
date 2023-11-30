/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 17:59:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int	main(void)
{
	FlagTrap	flagTrap("勇者");
	// FlagTrap	flagTrap;

	flagTrap.attack("うごくせきぞう");
	flagTrap.takeDamage(10);
	flagTrap.beRepaired(100);
	flagTrap.highFivesGuys();

	flagTrap.attack("キラーマシン");
	flagTrap.takeDamage(99);
	flagTrap.beRepaired(100);
	flagTrap.highFivesGuys();

	flagTrap.attack("ゲマ");
	flagTrap.takeDamage(100000000);
	flagTrap.beRepaired(100);

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex02");
}
