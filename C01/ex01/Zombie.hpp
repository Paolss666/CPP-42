/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/27 15:53:27 by npaolett         ###   ########.fr       */
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

Zombie* ZombieHorde(int N, std::string name);


#endif