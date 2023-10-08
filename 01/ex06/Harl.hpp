/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:50:28 by minabe            #+#    #+#             */
/*   Updated: 2023/10/08 11:33:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		void	debug(void);
		void 	info(void);
		void 	warning(void);
		void 	error(void);
	public:
		void	complain(std::string level);
};
