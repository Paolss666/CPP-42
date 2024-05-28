/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:36 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 12:29:39 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
    Zombie *n_Zombie = new Zombie[N];
    
    for(int i = 0; i < N; i++)
      n_Zombie[i].setNameZombie(name);

    return (n_Zombie);    
}

int     isNumberButNotZero(std::string const str)
{
    size_t j = 0;

    while (j < str.size())
    {
        if (str[j] > '0' && str[j] <= '9')
            j++;
        else
            return 0;
    }
    return 1;
}

int    isAlpha(std::string const str)
{
    size_t j = 0;

    while (j < str.size())
    {
        if ((str[j] >= 'a' && str[j] <= 'z') || ((str[j] >= 'A' && str[j] <= 'Z')))
            j++;
        else
            return 0;
    }
    return 1;
}
