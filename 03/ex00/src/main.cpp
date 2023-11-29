/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/11/26 12:30:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap("勇者");

	clapTrap.attack("スライム");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(10);

	clapTrap.attack("ホイミスライム");
	clapTrap.takeDamage(8);
	clapTrap.beRepaired(10);

	clapTrap.attack("ゲマ");
	clapTrap.takeDamage(100000000);
	clapTrap.beRepaired(10);

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex00");
}
