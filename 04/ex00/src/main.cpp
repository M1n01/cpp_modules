/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 19:59:55 by minabe           ###   ########.fr       */
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

	std::cout << "Type is " << dog->getType() << std::endl;
	std::cout << "Type is " << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	const WrongAnimal	*wrong_cat = new WrongCat();

	std::cout << "Type is " << wrong_cat->getType() << std::endl;
	wrong_cat->makeSound();

	delete wrong_cat;

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex00");
}
