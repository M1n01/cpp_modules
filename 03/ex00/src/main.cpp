/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:55:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap("勇者");

	clapTrap.attack("スライム");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(REPAIR);

	clapTrap.attack("ホイミスライム");
	clapTrap.takeDamage(8);
	clapTrap.beRepaired(REPAIR);

	clapTrap.attack("ゲマ");
	clapTrap.takeDamage(100000000);
	clapTrap.beRepaired(REPAIR);

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex00");
}
