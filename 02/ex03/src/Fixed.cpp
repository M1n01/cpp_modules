/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:35 by minabe            #+#    #+#             */
/*   Updated: 2023/11/21 22:12:24 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed(void) {}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &rhs)
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>(const Fixed &rhs)
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed	result;

	result._value = this->_value + rhs._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed	result;

	result._value = this->_value - rhs._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed	result;

	result._value = (this->_value * rhs._value) >> _bits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed	result;

	result._value = (this->_value << _bits) / rhs._value;
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}
