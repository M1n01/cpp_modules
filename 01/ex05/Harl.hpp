/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:50:28 by minabe            #+#    #+#             */
/*   Updated: 2023/10/08 12:17:40 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
	private:
		typedef void (Harl::*ComplainFunction)(void);
		void	debug(void);
		void 	info(void);
		void 	warning(void);
		void 	error(void);
	public:
		void	complain(std::string level);
};
