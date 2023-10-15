/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/10/15 17:12:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(0.0f, 1.0f);
	Point	c(1.0f, 1.0f);
	Point	point(0.5f, 0.5f);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle." << std::endl;
	else
		std::cout << "Point is outside the triangle." << std::endl;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q ex03");
}
