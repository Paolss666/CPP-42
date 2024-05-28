/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:00:07 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 12:35:13 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie random;
    
    random.setNameZombie(name);
    random.announce();
    return ;
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