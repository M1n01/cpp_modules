/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:18:53 by minabe            #+#    #+#             */
/*   Updated: 2023/12/03 17:51:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character & src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character	&Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
		_name = rhs._name;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	if (m->getType() != "ice" && m->getType() != "cure")
	{
		std::cerr << RED << "Error: invalid materia" << DEFAULT << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || 3 < idx || !_inventory[idx])
	{
		std::cerr << RED << "Error: invalid index" << DEFAULT << std::endl;
		return ;
	}
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 3 < idx || !_inventory[idx])
	{
		std::cerr << RED << "Error: invalid index" << DEFAULT << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
