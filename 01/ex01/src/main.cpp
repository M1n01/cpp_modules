/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/11/08 22:35:07 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	int		num;
	Zombie	*zombies;

	num = 5;
	zombies = zombieHorde(num, "HordeZombie");
	for (int i = 0; i < num; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}
