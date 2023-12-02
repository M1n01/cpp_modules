/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 13:07:25 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

int	main(void)
{
	FlagTrap	flagTrap("エースバーン");
	// FlagTrap	flagTrap;

	flagTrap.attack("トゲキッス");
	flagTrap.takeDamage(10);
	flagTrap.beRepaired(100);
	flagTrap.highFivesGuys();

	flagTrap.attack("サンダー");
	flagTrap.takeDamage(99);
	flagTrap.beRepaired(100);
	flagTrap.highFivesGuys();

	flagTrap.attack("ザシアン");
	flagTrap.takeDamage(100000000);
	flagTrap.beRepaired(100);

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex02");
}
