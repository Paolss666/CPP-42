/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:55:13 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 12:35:00 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name;
    
    std::cout << "enter the name of the zombies: ";
    if(!getline(std::cin, name) || std::cin.eof())
        return 1;
    while (!isAlpha(name))
    {
        std::cout << "enter the name of the zombies: ";
        if(!getline(std::cin, name) || std::cin.eof())
            return 1;
        else if (isAlpha(name))
            break;
    }
    
    Zombie* new_PetitZombie  = newZombie(name);

    new_PetitZombie->announce();

    delete(new_PetitZombie);

    std::string nwname;
    
    std::cout << "enter the name of the zombie for randomChump: ";
    if(!getline(std::cin, nwname) || std::cin.eof())
        return 1;
    while (!isAlpha(nwname))
    {
        std::cout << "enter the name of the zombie for randomChump: ";
        if(!getline(std::cin, nwname) || std::cin.eof())
            return 1;
        else if (isAlpha(nwname))
            break;
    }
    // RANDOMCHUMP ajout dans la pile (stack)
    randomChump(nwname);

    return (0);
}