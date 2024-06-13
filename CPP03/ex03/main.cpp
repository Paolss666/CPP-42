/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:05 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 13:27:49 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
/* #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp" */


int main(void)
{
    ClapTrap    clptrap("Jon");
    ScavTrap    scvtrap("COCO");
    FragTrap    frgtrap("RORO");
    DiamondTrap dmndtrap("DIAMANT");

    clptrap.visualizePoints();
    scvtrap.visualizePoints();
    frgtrap.visualizePoints();
    dmndtrap.visualizePoints();

    dmndtrap.WhoAmI();

    dmndtrap.attack(clptrap.getName());
	clptrap.takeDamage(dmndtrap.getDamage());

	dmndtrap.attack(scvtrap.getName());
	scvtrap.takeDamage(dmndtrap.getDamage());

	clptrap.beRepaired(5);
	dmndtrap.beRepaired(5);

    scvtrap.guardGate();
    dmndtrap.highFivesGuys();


    clptrap.visualizePoints();
    scvtrap.visualizePoints();
    frgtrap.visualizePoints();
    dmndtrap.visualizePoints();

    return 0;
}