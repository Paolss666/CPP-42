/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:20:19 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 12:22:08 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_hit = 100;
    this->_enrgyp = 50;
    this->_damage = 20;
    return ;
}


ScavTrap::ScavTrap(std::string const name): ClapTrap()
{
    /* std::cout << "ScavTrap constructor called with name " << std::endl; */
    this->_name = name;
    this->_hit = 100;
    this->_enrgyp = 50;
    this->_damage = 20;
    std::cout << "ScavTrap constructor called with name " << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap()
{
    std::cout << "ScavTrap cpy constructor called" << std::endl;
    this->_name = src.getName();
    this->_hit = src.getHit();
    this->_enrgyp = src.getEnergyP();
    this->_damage = src.getDamage();
    return ;
}


ScavTrap & ScavTrap::operator=(ScavTrap const &src)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_name = src.getName();
        this->_hit = src.getHit();
        this->_enrgyp = src.getEnergyP();
        this->_damage = src.getDamage();
    }
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Desctructor called" << std::endl;
    return ;

}



void    ScavTrap::attack(const std::string & target)
{

    if (this->_enrgyp == 0)
    {
        std::cout << "ScavTrap : No more energy points ! " << this->_name << " can't attack !"<< std::endl;
        return ;
    }
    if (this->_hit == 0)
	{
		std::cout << "ScavTrap : No more hit points ! " << this->_name << " can't attack ! " << std::endl;
		return ;
	}
    if (this->_name == target)
        std::cout << "ScavTrap : " << target << " is attacking himself !" << std::endl;
	else
		std::cout << "ScavTrap : " << this->_name << " attack " << target << " !" << std::endl; 
    this->_enrgyp--;
    return ;
}


void	ScavTrap::guardGate(void)
{
	
	std::cout << this->_name << " is now in gate keeper mode !"<< std::endl;
    return ;

}