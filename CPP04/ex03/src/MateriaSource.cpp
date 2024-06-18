/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:26:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/18 18:23:33 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    this->_setEmptyInventory();
    return ;
}


MateriaSource::MateriaSource(std::string const name):_name(name)
{
    this->_setEmptyInventory();
    return ;
}

MateriaSource::~MateriaSource()
{
    std::cout << this->_name << " : Destructor called" << std::endl;
    return;
}


MateriaSource::MateriaSource(MateriaSource const & src)
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

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this!= &src)
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
    return(*this);
}


void    MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return ;
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (!(this->_inventory[i]))
        {
            this->_inventory = materia;
            return;
        }
    }
}


void        MateriaSource::_setEmptyInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
        this->_inventory[i] = NULL;
    return ;
}

void    MateriaSource::_deleteInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (this->_inventory[i] != NULL)
            delete _inventory[i];
    }
    this->_setEmptyInventory();
    return;
}