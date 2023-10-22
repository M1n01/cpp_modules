/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:59:22 by minabe            #+#    #+#             */
/*   Updated: 2023/10/22 21:23:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ScavTrap.hpp"
# include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		void	whoAmI(void);
};
