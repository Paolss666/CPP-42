/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:02:10 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 15:30:32 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newtype):_type(newtype){
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string& Weapon::getType(void)const {
    return this->_type;
}

void    Weapon::setType(const std::string& new_type){
    this->_type = new_type;
    return ;
}