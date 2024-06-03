/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:41:18 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 14:17:28 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): _Name()
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Zombie::~Zombie()
{
    std::cout << this->_Name << "> Destructor called" << std::endl;
    return ;
}

void Zombie::setNameZombie(std::string name)
{
    this->_Name = name;
    return ;
}


void Zombie::announce(void){  

    std::cout << this->_Name + ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
    return ; 
}

