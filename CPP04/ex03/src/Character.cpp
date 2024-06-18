/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:22:44 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/18 16:04:06 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Character.hpp"

Character::Character(void)
{
    this->_setEmptyInventory();
    return;
}

Character::Character(std::string const name):_name(name)
{
    this->_setEmptyInventory();
    return;
}

Character::Character(Character const & src)
{
    this->_name = src._name;
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    return ;
}

Character::~Character(void)
{
    this->_deleteInventory();
    return ;
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        this->_name = src._name;
        for (int i = 0; i < this->_inventorySize; i++)
        {
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::setName(std::string const name)
{
	this->_name = name;
	return ;
}

void    Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (!(this->_inventory[i]))
        {
            this->_inventory = m;
            return;
        }
    }
    return ;
}


void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= this->_inventorySize)
    {
        std::cout << this->_name << " can't unequip, idx is : " << idx << " and has to be between 0 or 3." << std::endl;
        return ;
    }
    else if (this->_inventory[idx] == NULL)
    {
        std::cout << this->_name << " can't unequip, idx is : " << idx << " it's already empty" << std::endl;
        return ;
    }
    std::cout << this->_name << " has unequiped his idx : " << idx 
	<< " of the materia " << this->_inventory[idx]->getType() << std::endl;
	this->_inventory[idx] = NULL;
    return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << this->_name << " can't use the materia at idx : " << idx 
		<< "], this idx number is not valid, it has to be between 0 and 3" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " can't use this idx : " << idx 
		<< " materia, there's none here" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	return ;
}

void	Character::displayInventory(void) const
{
	std::cout << this->_name << "'s inventory :" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
			std::cout << "idx [" << i << "] is empty" << std::endl;
		else
			std::cout << "idx [" << i << "] : " << this->_inventory[i]->getType() << std::endl;
	}
	return ;
}


void        Character::_setEmptyInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
        this->_inventory[i] = NULL;
    return ;
}

void    Character::_deleteInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (this->_inventory[i] != NULL)
            delete _inventory[i];
    }
    this->_setEmptyInventory();
    return;
}

