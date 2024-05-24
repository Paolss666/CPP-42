/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/24 18:11:45 by npaolett         ###   ########.fr       */
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
    void    setName(std::string const name); 
    std::string   getName(void);
    void    announce(void);
    void randomChump( std::string name );
    Zombie* newZombie( std::string name );
};



#endif