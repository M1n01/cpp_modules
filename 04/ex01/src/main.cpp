/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 14:54:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal	*animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();

	static_cast<Dog *>(animals[0])->getBrain()->setIdea(0, "Bone!!");
	static_cast<Cat *>(animals[1])->getBrain()->setIdea(0, "Tuna!!");

	animals[2] = new Dog(*static_cast<Dog *>(animals[0]));
	animals[3] = new Cat(*static_cast<Cat *>(animals[1]));

	for (int i = 0; i < 4; i++)
	{
		Dog	*dog = dynamic_cast<Dog *>(animals[i]);
		if (dog)
			std::cout << "Dog Brain: " << dog->getBrain()->getIdea(0) << std::endl;

		Cat	*cat = dynamic_cast<Cat *>(animals[i]);
		if (cat)
			std::cout << "Cat Brain: " << cat->getBrain()->getIdea(0) << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex01");
}
