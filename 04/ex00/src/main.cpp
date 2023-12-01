/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:42:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << cat->getType() << ": ";
	cat->makeSound();

	std::cout << meta->getType() << ": ";
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();

	delete wrongCat;

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex00");
}
