/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 14:49:57 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name):_name(name), _weapon(NULL){
    return ;
}


HumanB::~HumanB(void)
{
    return ;
}

void    HumanB::attack()
{
    if (this->_weapon != NULL && !this->_weapon->getType().empty())
    {
        std::cout << this->_name << ": attack with their " 
            << _weapon->getType() << std::endl;
        return ;
    }
    else
        std::cout << this->_name << ": attack with nothing" << std::endl;
    return ; 
}

void    HumanB::setWeapon(Weapon& weapon){

    this->_weapon = &weapon;
    return;
}