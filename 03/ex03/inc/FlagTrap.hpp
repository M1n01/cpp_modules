/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:08:36 by minabe            #+#    #+#             */
/*   Updated: 2023/11/30 09:57:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		~FlagTrap(void);
		void	highFivesGuys(void);
};
