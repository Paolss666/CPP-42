/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:42 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 16:19:10 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack(void);
        void setWeapon(Weapon& weapon);
};

#endif
