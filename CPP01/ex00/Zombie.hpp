/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 12:35:54 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Zombie
{
    private:
        std::string _Name;
    public:
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
        void setNameZombie(std::string name);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
int    isAlpha(std::string const str);

#endif