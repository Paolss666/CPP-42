/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:54:39 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/05 13:45:07 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixe(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Costructor intNb fixe;

Fixed::Fixed(int const nb): _fixe(nb << _bits)
{
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(float const nbFloat): _fixe(roundf( nbFloat * (1 << _bits)))
{
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}


Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixe = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    return (this->_fixe);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixe = raw;
    return ;
}

/* Considerando che _fixe è il valore fisso memorizzato e _bits rappresenta
 il numero di bit della parte frazionaria, la conversione
corretta dovrebbe essere fatta dividendo _fixe per 2^bits. */

float Fixed::toFloat(void)const{

    return ((float)this->_fixe  / (1 << this->_bits));
}

int Fixed::toInt(void)const{

    return (this->_fixe >> this->_bits);
}


std::ostream & operator<<(std::ostream & os, const Fixed &rhs)
{
    os << rhs.toFloat();
    return (os);
}

