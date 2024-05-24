/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:41:18 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/24 18:11:07 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(/* args */)
{
    std::cout << "Costructeur colled" << std::endl;
    return ;
}

Zombie::~Zombie()
{
    std::cout << "Destructeur colled" << std::endl;
    return ;
}

void    Zombie::announce(void){  

    std::cout << this->_Name + ":" << ">: BraiiiiiiinnnzzzZ..." << std::endl;
    return ; 
}

Zombie* Zombie::newZombie(std::string name)
{
    Zombie  zombie;
    
    this->_Name = name;
    return (zombie);
}