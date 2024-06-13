/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:42:43 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 12:15:16 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap clptr("Momo");
    ClapTrap clptr1("Loulou");

    ScavTrap scvtrp("King");

    FragTrap frgtrp("FROG");

    clptr.visualizePoints();
    clptr1.visualizePoints();

    scvtrp.visualizePoints();
    frgtrp.visualizePoints();

    clptr1.attack(clptr.getName());
    clptr1.setDamage(50);
    clptr.takeDamage(50);

    clptr.visualizePoints();
    clptr1.visualizePoints();

    scvtrp.visualizePoints();
    frgtrp.visualizePoints();

    clptr1.beRepaired(3);

	clptr1.attack(scvtrp.getName());
	scvtrp.takeDamage(2);

    frgtrp.highFivesGuys();

    for (unsigned int i = 0; i < 20; i++)
    {
        frgtrp.attack(scvtrp.getName());
        frgtrp.setDamage(i);
        scvtrp.takeDamage(frgtrp.getDamage());
    }
	
	scvtrp.attack(clptr1.getName());
	clptr1.takeDamage(scvtrp.getDamage());

	scvtrp.guardGate();
    frgtrp.highFivesGuys();


	clptr.visualizePoints();
	clptr1.visualizePoints();
	scvtrp.visualizePoints();

    return 0;
}