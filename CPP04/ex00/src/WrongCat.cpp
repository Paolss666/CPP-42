/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:36:22 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 12:17:23 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat class: Default Constructor called" << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal()
{
    this->_type = src._type;
    std::cout << "WrongCat class : cpy constructor called" << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    std::cout << "WrongCat class : cpy operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat class : Desctructor called" << std::endl;
    return;
}

void    WrongCat::makeSound(void)const
{
    if (this->_type == "WrongCat")
        std::cout << this->_type << " : WRONGMiauuuuooo !!" << std::endl;
    else if (this->_type == "WrongAnimal")
        std::cout << this->_type  << " : Random WrongAnimal sound..." << std::endl;
    return;
}