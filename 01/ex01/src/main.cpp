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

#include "Zombie.hpp"

int	main(void)
{
	int		num;
	Zombie	*zombies;

	num = 5;
	zombies = zombieHorde(num, "HordeZombie");
	for (int i = 0; i < num; i++)
		zombies[i].announce(void);
	delete[] zombies;
	return (0);
}

__attribute__((destructor))
static void destructor(void) {
	system("leaks -q ex01");
}
