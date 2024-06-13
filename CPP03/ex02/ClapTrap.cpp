/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:05:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/13 13:18:40 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap():_hit(0), _enrgyp(0),_damage(0)
{
    std::cout << "Constructor default called" << std::endl;
    return;
}


ClapTrap::ClapTrap(std::string const name):_name(name), _hit(10), _enrgyp(10),_damage(0)
{
    std::cout << "Constructor  called" << std::endl;
    return ;
}


ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
    return ;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void    ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}



void    ClapTrap::setHit(unsigned int const hit)
{
    this->_hit = hit;
}


void    ClapTrap::setEnergyP(unsigned int const enrgyp)
{
    this->_enrgyp = enrgyp;
}


void    ClapTrap::setDamage(unsigned int const dama_damage)
{
    this->_damage = dama_damage;
}


std::string    ClapTrap::getName(void) const
{
    return (this->_name);
}



unsigned int    ClapTrap::getHit(void) const
{
    return (this->_hit);
}


unsigned int  ClapTrap::getEnergyP(void) const
{
    return (this->_enrgyp);
}


unsigned int   ClapTrap::getDamage(void) const
{
    return(this->_damage);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
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

void    ClapTrap::attack(const std::string &target)
{
    if (this->_enrgyp > 0 && this->_hit > 0)
    {
        std::cout << this->_name << " attack " << target << ", causing " << this->_damage << " points of damage" << std::endl;
        this->_enrgyp -= 1;
        return ;  
    }
    if (this->_enrgyp <= 0)
    {
        std::cout << this->_name << " can't do anything" << " becouse don't have energy points " << std::endl;
        return;
    }
    if (this->_hit <= 0)
    {
        std::cout << this->_name << " can't do anything" << " becouse don't have hit points "<< std::endl;
        return ;
    }
    // std::cout << this->_name << " can't do anything" << " becouse don't have energy points-> " << this->_enrgyp << " or hit points-> " << this->_hit << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit <= 0)
    {
        std::cout << this->_name << " can't do anything" << " becouse don't have hit points " << std::endl;
        return ;
    }
    else if (this->_hit > 0)
    {
        std::cout << this->_name << " amount of hit  before damage = " << this->_hit << std::endl;
        
        // if ()
        if ((this->_hit < amount))
            this->_hit  = 0;
        else
            this->_hit -= amount;
        
        std::cout << this->_name << " amount of hit  before after = " << this->_hit << std::endl;
    }
    else if (this->_enrgyp > 0 && this->_hit > 0)
    {
        std::cout << this->_name << " take damage" << "amount = " << amount << " and hit now is = " << this->_hit << std::endl;
        return ;
    }
    // std::cout << this->_name << " can't do anything" << " becouse don't have energy points-> " << this->_enrgyp << " or hit points-> " << this->_hit << std::endl;
    return;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->_name << " amount of hit  = " << this->_hit << std::endl;
    
    this->_hit += amount;
    if (this->_hit > 10)
        this->setHit(10);
    if (this->_enrgyp > 0 && this->_hit > 0)
    {
        std::cout << this->_name << " take a Riparative potion " << "amount = " << amount << " and hit now is = " << this->_hit << std::endl;
        this->_enrgyp -= 1;
        return ;
    }
    std::cout << this->_name << "can't do anything" << " becouse don't have energy points or hit points" << std::endl;

    return;
}

void	ClapTrap::visualizePoints()
{

	std::cout  << "┌─────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "│" ;
	std::cout << std::setw(22) << this->_name ;
	std::cout << " total point : " << std::setw(19)  << "│" << std::endl;
	
	std::cout << "│"<< std::setw(3) << this->_hit<< " hit points  " << std::setw(3) << this->_enrgyp << " energy points  " << std::setw(3) << this->_damage << " attack damage " << "|" << std::endl;
	std::cout << "└─────────────────────────────────────────────────────┘" << std::endl;
}