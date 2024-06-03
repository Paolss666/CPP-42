/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:41:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/03 15:48:45 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void): _fixe(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixe);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Setter called" << std::endl;
    this->_fixe = raw;
    return ;
}


// OPERATOR <-----------

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixe = src.getRawBits();
    return (*this);
}