/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:21:41 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/13 13:20:04 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    protected:
    
    public:
        FragTrap();
        FragTrap(std::string const name);
        FragTrap(FragTrap const &src);
        FragTrap & operator=(FragTrap const &src);
        ~FragTrap();

        void    highFivesGuys(void);
};



#endif