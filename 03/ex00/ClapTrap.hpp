/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:22:14 by minabe            #+#    #+#             */
/*   Updated: 2023/10/15 18:47:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		void	attack(const std::string&target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
