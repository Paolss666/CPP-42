/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:05:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 17:18:39 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap():_name(NULL), _hit(0), _enrgyp(0),_domage(0)
{
    std::cout << "Constructor default called" << std::endl;
    return;
}


ClapTrap::ClapTrap(std::string const name):_hit(10), _enrgyp(10),_domage(0)
{
    // this->setName(name);
    // this->setDomage(0);
    // this->setDomage(0);
    this->setName(name);
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


void    ClapTrap::setDomage(unsigned int const domage)
{
    this->_domage = domage;
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


unsigned int   ClapTrap::getDomage(void) const
{
    return(this->_domage);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_hit = src.getHit();
        this->_enrgyp = src.getEnergyP();
        this->_domage = src.getDomage();
    }
    return (*this);
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_enrgyp > 0 && this->_hit > 0)
    {
        std::cout << this->_name << " attack " << target << ", causing " << this->_domage << " points of damage" << std::endl;
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

void    ClapTrap::takeDomage(unsigned int amount)
{
    if (this->_hit <= 0)
    {
        std::cout << this->_name << " can't do anything" << " becouse don't have hit points " << std::endl;
        return ;
    }
    else if (this->_hit > 0)
    {
        std::cout << this->_name << " amount of hit  before domage = " << this->_hit << std::endl;
        
        // if ()
        if ((this->_hit < amount))
            this->_hit  = 0;
        else
            this->_hit -= amount;
        
        std::cout << this->_name << " amount of hit  before after = " << this->_hit << std::endl;
    }
    else if (this->_enrgyp > 0 && this->_hit > 0)
    {
        std::cout << this->_name << " take domage " << "amount = " << amount << " and hit now is = " << this->_hit << std::endl;
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