/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 13:52:57 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>


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
int     isNumber(std::string const str);
int    isAlpha(std::string const str);

#endif