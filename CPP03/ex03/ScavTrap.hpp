/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:06:09 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 13:20:30 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string const name);
        ScavTrap(ScavTrap const & src);
        ScavTrap & operator=(ScavTrap const & src);
        ~ScavTrap();
        void    attack(const std::string& target);
        void    guardGate();
    
    protected:
};



#endif