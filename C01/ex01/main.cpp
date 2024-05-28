/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 12:31:41 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
    std::string value;
    std::string name;

    (void)av;
    if (ac > 1)
    {
        std::cerr << "Bad numbers of arguments" << std::endl;
        return 1;
    }
    
    
    std::cout << "enter number of zombie: ";
    if(!getline(std::cin, value) || std::cin.eof())
        return 1;
    
    while (!isNumberButNotZero(value))
    {
        std::cout << "enter number of zombie: ";
        if(!getline(std::cin, value) || std::cin.eof())
            return 1;
        else if (isNumberButNotZero(value))
            break;
    }
    
    int n = atoi(value.c_str());
    
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

    
    Zombie* nw_zombie = ZombieHorde(n, name);

    for(int i = 0; i < n; i++)
        nw_zombie[i].announce();

    delete [] nw_zombie;

    return 0;
}
