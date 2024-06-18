/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:54:26 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/18 20:07:04 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Ice.hpp"

Ice::Ice(/* args */):AMateria("ice")
{
    return ;
}


Ice::Ice(Ice const &src):AMateria()
{
    this->_type = src._type;
    return ;
}


Ice & Ice::operator=(Ice const &src)
{
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Ice::~Ice(void)
{
    return;
}



Ice *Ice::clone(void)const{
    return new Ice();
}


void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}