/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:55:13 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/27 14:55:32 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* new_PetitZombie  = newZombie("Frank");

    new_PetitZombie->announce();

    delete(new_PetitZombie);

    // RANDOMCHUMP ajout dans la pile (stack)
    randomChump("new Frank");

    return (0);
}