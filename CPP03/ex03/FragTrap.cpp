/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:24:16 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 13:22:09 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hit = 100;
    this->_enrgyp = 50;
    this->_damage = 20;
    return ;
}


FragTrap::FragTrap(std::string const name): ClapTrap()
{
    /* std::cout << "FragTrap constructor called with name " << std::endl; */
    this->_name = name;
    this->_hit = 100;
    this->_enrgyp = 50;
    this->_damage = 20;
    std::cout << "FragTrap constructor called with name " << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap()
{
    std::cout << "FragTrap cpy constructor called" << std::endl;
    this->_name = src.getName();
    this->_hit = src.getHit();
    this->_enrgyp = src.getEnergyP();
    this->_damage = src.getDamage();
    return ;
}


FragTrap & FragTrap::operator=(FragTrap const &src)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_name = src.getName();
        this->_hit = src.getHit();
        this->_enrgyp = src.getEnergyP();
        this->_damage = src.getDamage();
    }
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Desctructor called" << std::endl;
    return ;

}


void        FragTrap::highFivesGuys(void)
{
    if (this->_hit <= 0 || this->_enrgyp <= 0)
    {
        std::cout <<  this->_name << " can't do high fives, low energy" << std::endl;	
        return ;
    }
    std::cout << this->_name  << " : high fives anyone !?" << std::endl;
    return ;
}

