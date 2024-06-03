/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:21:08 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 14:51:47 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
         Weapon club = Weapon("crude spiked club");
         HumanB jim("Jim");
         jim.attack();
         jim.setWeapon(club);
         jim.attack();
         club.setType("some other type of club");
         jim.attack();
    }
    return 0;
}