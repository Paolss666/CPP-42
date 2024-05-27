/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:41:18 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/27 15:44:15 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): _Name()
{
    std::cout << "Costructeur colled" << std::endl;
    return ;
}

Zombie::~Zombie()
{
    std::cout << "Destructeur colled" << std::endl;
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

// Zombie* newZombie(std::string name)
// {
//     Zombie*  nw_zombie = new Zombie;
    
//     nw_zombie->setNameZombie(name);
//     return (nw_zombie);
// }

// void randomChump( std::string name )
// {
//     Zombie random;
    
//     random.setNameZombie(name);
//     random.announce();
//     return ;
// }