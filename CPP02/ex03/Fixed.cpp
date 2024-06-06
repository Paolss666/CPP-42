/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:54:39 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 11:00:57 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixe(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return ;
}

// Costructor intNb fixe;

Fixed::Fixed(int const nb): _fixe(nb << _bits)
{
    // std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(float const nbFloat): _fixe(roundf( nbFloat * (1 << _bits)))
{
    // std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed & src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}


// OPERATOR <-----------

Fixed & Fixed::operator=(Fixed const & src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixe = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
    // std::cout << "assignment operator called" << std::endl;
    os << rhs.toFloat();
    return (os);
}

bool Fixed::operator>(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe > src._fixe) 
        return (true);
    return (false);
}

bool Fixed::operator<(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe < src._fixe) 
        return (true);
    return (false);
}


bool Fixed::operator==(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe ==  src._fixe) 
        return (true);
    return (false);
}



bool Fixed::operator>=(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe >= src._fixe) 
        return (true);
    return (false);
}


bool Fixed::operator<=(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe <= src._fixe) 
        return (true);
    return (false);
}


bool Fixed::operator!=(Fixed const & src) const
{
    // std::cout << "assignment operator == called" << std::endl;
    if (this->_fixe != src._fixe) 
        return (true);
    return (false);
}

Fixed Fixed::operator+(Fixed const & src) const
{
    Fixed result;
    
    result.setRawBits(this->_fixe + src.getRawBits());

    return (result);
}


Fixed Fixed::operator-(Fixed const & src) const
{
    Fixed result;
    
    result.setRawBits(this->_fixe - src.getRawBits());
    return (result);
}

Fixed Fixed::operator*(Fixed const & src) const
{
    Fixed result;
    
    result.setRawBits(this->_fixe * (src.getRawBits() / (1 << this->_bits)));

    return (result);
}

Fixed Fixed::operator/(Fixed const & src) const
{
    Fixed result;
    
    result.setRawBits((this->_fixe << this->_bits) / src.getRawBits());

    return (result);
}

Fixed Fixed::operator++(){

    this->_fixe++;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	this_tmp(*this);

	++(*this);
	return (this_tmp);
}

Fixed Fixed::operator--(){

    this->_fixe--;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	this_tmp(*this);

	--(*this);
	return (this_tmp);
}


Fixed &Fixed::min(Fixed &src, Fixed &src2){
    if (src.getRawBits() < src2.getRawBits())
        return (src);
    return (src2);
}

Fixed const &Fixed::min(Fixed const &src, Fixed const &src2){
    if (src.getRawBits() < src2.getRawBits())
        return (src);
    return (src2);
}


Fixed &Fixed::max(Fixed &src, Fixed &src2){
    if (src.getRawBits() > src2.getRawBits())
        return (src);
    return (src2);
}

Fixed const &Fixed::max(Fixed const &src, Fixed const &src2){
    if (src.getRawBits() > src2.getRawBits())
        return (src);
    return (src2);
}