/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:59:34 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 12:34:46 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie*  nw_zombie = new Zombie;
    
    nw_zombie->setNameZombie(name);
    return (nw_zombie);
}