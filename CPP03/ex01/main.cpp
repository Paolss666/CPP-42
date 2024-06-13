/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:42:43 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 12:20:23 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clptr("Momo");
    ClapTrap clptr1("Loulou");

    ScavTrap scvtrp("King");

    clptr.visualizePoints();
    clptr1.visualizePoints();

    scvtrp.visualizePoints();

    clptr1.attack(clptr.getName());
     clptr1.setDamage(10);
    clptr.takeDamage(10);

    clptr.visualizePoints();
    clptr1.visualizePoints();

    scvtrp.visualizePoints();

    clptr1.beRepaired(3);

	clptr1.attack(scvtrp.getName());
	scvtrp.takeDamage(2);
	
	scvtrp.attack(clptr1.getName());
	clptr1.takeDamage(scvtrp.getDamage());

	scvtrp.guardGate();

	clptr.attack(scvtrp.getName());
	scvtrp.takeDamage(100);

	clptr.visualizePoints();
	clptr1.visualizePoints();
	scvtrp.visualizePoints();
    return 0;
}