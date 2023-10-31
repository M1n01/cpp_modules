/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/10/31 21:34:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("HeapZombie");
	zombie->announce();
	delete zombie;

	randomChump("StackZombie");
	return (0);
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}
