/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:18 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:47:41 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap("ピカチュウ");
	// ClapTrap	clapTrap;

	clapTrap.attack("ポッポ");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(10);

	clapTrap.attack("イワーク");
	clapTrap.takeDamage(8);
	clapTrap.beRepaired(10);

	clapTrap.attack("カイリュー");
	clapTrap.takeDamage(100000000);
	clapTrap.beRepaired(10);

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex00");
}
