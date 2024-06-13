/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:03:14 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 13:23:18 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(/* args */): FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap costructor default called" << std::endl;
    this->_hit = FragTrap::_hit;
    this->_hit = ScavTrap::_enrgyp;
    this->_hit = FragTrap::_damage;

}

DiamondTrap::DiamondTrap(std::string name): FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_name"), _name(name)
{
    std::cout << "DiamondTrap costructor called" << "initilized name = " << name << std::endl;
    this->_hit = FragTrap::_hit;
    this->_hit = ScavTrap::_enrgyp;
    this->_hit = FragTrap::_damage;

}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(),  FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = src.getName();
	this->_hit = src.getHit();
	this->_enrgyp = src.getEnergyP();
	this->_damage = src.getDamage();
	return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_hit = src.getHit();
        this->_enrgyp = src.getEnergyP();
        this->_damage = src.getDamage();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Detructor called name = " << this->_name << std::endl;
    return ;
}


void    DiamondTrap::WhoAmI()
{
    std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
    return ;
}
