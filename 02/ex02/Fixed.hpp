/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:37 by minabe            #+#    #+#             */
/*   Updated: 2023/10/10 09:00:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define DEBUG 1

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
		static const int	_fractionalFactor = 1 << _bits;
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs);
		bool	operator<(const Fixed &rhs);
		bool	operator>(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		friend std::ostream	&operator<<(std::ostream &os, const Fixed &rhs);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
