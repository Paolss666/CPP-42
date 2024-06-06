/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:13 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 15:05:59 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>


class ClapTrap
{
    private:
        std::string                 _name;
        unsigned int               _hit;
        unsigned int              _enrgyp;
        unsigned int              _domage;
    public:
        ClapTrap();
        ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &src);
        ClapTrap &operator=(ClapTrap const &src);
        ~ClapTrap();
        void    setName(const std::string &name);
        void    setHit(unsigned int const hit);
        void    setEnergyP(unsigned int const enrgyp);
        void    setDomage(unsigned int const domage);
        std::string         getName(void)const ;
        unsigned int        getHit(void)const;
        unsigned int        getEnergyP(void)const;
        unsigned int        getDomage(void)const;
        void    attack(const std::string &target);
        void    takeDomage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        
};


#endif
