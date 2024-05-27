/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:36 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/27 15:55:01 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
    Zombie *n_Zombie = new Zombie[N];
    
    for(int i = 0; i <= N; i++)
      n_Zombie[i].setNameZombie(name);

    return (n_Zombie);    
}
