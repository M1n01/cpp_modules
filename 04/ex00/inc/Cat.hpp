/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:13:30 by minabe            #+#    #+#             */
/*   Updated: 2023/12/01 21:44:13 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &src);
		Cat	&operator=(const Cat &rhs);
		~Cat(void);

		void	makeSound() const;
};
