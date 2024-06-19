/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:26:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/19 17:21:07 by npaolett         ###   ########.fr       */
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
/*     std::cout << this->_name << " : Destructor called" << std::endl; */
    this->_deleteInventory();
    return;
}


MateriaSource::MateriaSource(MateriaSource const & src)
{
    this->_name = src._name;
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (src._sInventory[i])
            this->_sInventory[i] = src._sInventory[i]->clone();
        else
            this->_sInventory[i] = NULL;
    }
    return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this != &src)
    {    
        this->_name = src._name;
        for (int i = 0; i < this->_inventorySize; i++)
        {
            if (this->_sInventory[i])
            {
                delete this->_sInventory[i];
                this->_sInventory[i] = NULL;
            }
            if (src._sInventory[i])
                this->_sInventory[i] = src._sInventory[i]->clone();
            else
                this->_sInventory[i] = NULL;
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
        if (!(this->_sInventory[i]))
        {
            this->_sInventory[i] = materia;
            return;
        }
    }
    // delete materia;
}


AMateria    *MateriaSource::createMateria(std::string const &type)
{
    if (!type.length())
        return 0;
    for (int i = 0; i < this->_inventorySize ; i++)
    {
        if (this->_sInventory[i] && this->_sInventory[i]->getType() == type)
            return (this->_sInventory[i]->clone());
    }
    return 0;
}

void        MateriaSource::_setEmptyInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
        this->_sInventory[i] = NULL;
    return ;
}

void    MateriaSource::_deleteInventory()
{
    for (int i = 0; i < this->_inventorySize; i++)
    {
        if (this->_sInventory[i] != NULL)
            delete _sInventory[i];
    }
    this->_setEmptyInventory();
    return;
}