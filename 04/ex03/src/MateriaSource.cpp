/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:30:06 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 16:30:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_count = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_count = 0;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete _materias[i];
			_materias[i] = NULL;
		}
		_count = rhs._count;
		for (int i = 0; i < _count; i++)
			_materias[i] = rhs._materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = NULL;
	}
}

void			MateriaSource::learnMateria(AMateria* materia)
{
	if (_count < 4 && materia)
	{
		_materias[_count] = materia;
		_count++;
	}
}

AMateria*		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _count; i++)
	{
		if (_materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (NULL);
}
