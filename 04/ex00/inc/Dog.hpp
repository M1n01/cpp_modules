/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:13:36 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:44:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &src);
		Dog	&operator=(const Dog &rhs);
		~Dog(void);

		void	makeSound() const;
};
