/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:14:08 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 14:50:47 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"



HumanA::HumanA(std::string const name , Weapon& weapon): _name(name), _weapon(weapon){
    return ;
}

HumanA::~HumanA(void)
{
    return ;
}



void    HumanA::attack()
{
    if (!_weapon.getType().empty())
    {
        std::cout << this->_name << ": attack with their " 
            << _weapon.getType() << std::endl;
    }
    else
        std::cout << this->_name << ": attack with nothing " << std::endl;
    return ; 
}