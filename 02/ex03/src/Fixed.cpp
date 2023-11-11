/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:48:35 by minabe            #+#    #+#             */
/*   Updated: 2023/11/11 17:54:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &rhs)
{
	std::cout << "Less than operator called" << std::endl;
	return (this->_value < rhs._value);
}

bool	Fixed::operator>(const Fixed &rhs)
{
	std::cout << "Greater than operator called" << std::endl;
	return (this->_value > rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	std::cout << "Less than or equal to operator called" << std::endl;
	return (this->_value <= rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	std::cout << "Greater than or equal to operator called" << std::endl;
	return (this->_value >= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	std::cout << "Equal to operator called" << std::endl;
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	std::cout << "Not equal to operator called" << std::endl;
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	Fixed	result;

	std::cout << "Addition operator called" << std::endl;
	result._value = this->_value + rhs._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	Fixed	result;

	std::cout << "Subtraction operator called" << std::endl;
	result._value = this->_value - rhs._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed	result;

	std::cout << "Multiplication operator called" << std::endl;
	result._value = (this->_value * rhs._value) >> _bits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	Fixed	result;

	std::cout << "Division operator called" << std::endl;
	result._value = (this->_value << _bits) / rhs._value;
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	std::cout << "Pre-increment operator called" << std::endl;
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	std::cout << "Post-increment operator called" << std::endl;
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	std::cout << "Pre-decrement operator called" << std::endl;
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	std::cout << "Post-decrement operator called" << std::endl;
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &rhs)
{
	os << rhs.toFloat();
	return (os);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	std::cout << "Min function called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	std::cout << "Min function called" << std::endl;
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	std::cout << "Max function called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	std::cout << "Max function called" << std::endl;
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
