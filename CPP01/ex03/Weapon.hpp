/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:59:47 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 15:30:22 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string> 
#include <iomanip>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string newtype);
        ~Weapon(void);
        const std::string& getType(void) const ;
        void         setType(const std::string& new_type);
};

#endif