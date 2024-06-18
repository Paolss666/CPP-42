/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:45:01 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/18 20:06:08 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cure.hpp"

Cure::Cure(/* args */):AMateria("cure")
{
    return ;
}


Cure::Cure(Cure const &src):AMateria()
{
    this->_type = src._type;
    return ;
}


Cure & Cure::operator=(Cure const &src)
{
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Cure::~Cure(void)
{
    return;
}



Cure *Cure::clone(void)const{
    return new Cure();
}


void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
    return;
}