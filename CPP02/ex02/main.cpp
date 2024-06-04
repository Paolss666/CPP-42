/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:05:55 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/04 12:37:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

Fixed a;
// Fixed c;
// Fixed d (5.05f);
// Fixed c (2);

Fixed const b( Fixed (5.05f) * Fixed (2));
// Fixed const c( Fixed (5.05f) * Fixed (2));

// Fixed const c( Fixed (5.05f) / Fixed (2));

// Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
// Fixed const f( Fixed( 5.05f ) + Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;
// std::cout << c << std::endl;
// std::cout << "a + b --> " << a + b << std::endl;
// std::cout << "a --> " << a<< std::endl;


std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}