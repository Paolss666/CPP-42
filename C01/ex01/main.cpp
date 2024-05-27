/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/27 16:43:08 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string value;
    std::cout << "enter number of zombie: ";
    if(!getline(std::cin, value) || std::cin.eof())
        return 1;
   
    int n = atoi(value.c_str());
    if (n <= 0)
    {
        std::cerr << "negatif" << std::endl;
        return 1;
    }
    
    Zombie* nw_zombie = ZombieHorde(n, "Frank");

    for(int i = 0; i < n; i++)
    {
        // std::cout << "number zombie: " << i << std::endl;
        nw_zombie[i].announce();
        // std::cout << "number of zombie: " << i << std::endl;
    }
    delete [] nw_zombie;
    return 0;
}
