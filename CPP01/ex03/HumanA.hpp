/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:12:09 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 16:00:33 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon& _weapon;
public:
    HumanA(std::string const name, Weapon& weapon);
    ~HumanA(void);
    void attack(void);
};

#endif

