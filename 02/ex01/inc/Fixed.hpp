/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:37 by minabe            #+#    #+#             */
/*   Updated: 2023/11/21 17:36:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		Fixed	&operator=(const Fixed &rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs);
