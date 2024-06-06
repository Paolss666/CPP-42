/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:14:20 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 17:13:15 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Boubou("BOUBOu");
    ClapTrap coco("coco");
    unsigned int amount = 4;
    // ClapTrap cpyBoucou((Boubou));

    Boubou.setDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    // Boubou.takeDomage(2);
    // Boubou.takeDomage(2);
    // Boubou.takeDomage(2);
    // Boubou.takeDomage(2);
    // Boubou.takeDomage(2);
    // Boubou.takeDomage(2);
    Boubou.attack("COCCO");
    Boubou.beRepaired(100);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    // coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");
    coco.takeDomage(amount);
    Boubou.attack("coco");



    // Boubou.beRepaired(10);
}