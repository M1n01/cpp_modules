/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 10:07:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack(void);
		club.setType("some other type of club");
		bob.attack(void);
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack(void);
		jim.setWeapon(club);
		jim.attack(void);
		club.setType("some other type of club");
		jim.attack(void);
	}
	return (0);
}

__attribute__((destructor))
static void destructor(void) {
	system("leaks -q ex03");
}
