/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:45:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 18:27:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	/* AAnimalの直接のインスタンス化を試みる（これはエラーを引き起こす）*/
	// AAnimal* animal = new AAnimal();

	// DogとCatのオブジェクトを作成
	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();

	// 各動物の音を確認
	dog->makeSound(); // "Bark"
	cat->makeSound(); // "Meow"

	// メモリの解放
	delete dog;
	delete cat;
	return (0);
}

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex02");
}
