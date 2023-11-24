/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:47:47 by minabe            #+#    #+#             */
/*   Updated: 2023/11/24 09:24:51 by minabe           ###   ########.fr       */
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
		std::cout << BLUE << "Point is inside the triangle." << DEFAULT << std::endl;
	else
		std::cout << RED << "Point is outside the triangle." << DEFAULT << std::endl;
	return (0);
}
