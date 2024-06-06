/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:05:55 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 12:19:45 by npaolett         ###   ########.fr       */
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

Fixed const c( Fixed (5.05f) / Fixed (2));

Fixed const d( Fixed( 2 ) - Fixed( 5.05f ) );
Fixed const f( Fixed( 2100 ) + Fixed( 5.05f ) );
Fixed const beta( Fixed( 2100 ) + Fixed( -10 ) );



std::cout << "TEST OPERATOR ++ //" << std::endl;
std::cout << std::endl; 
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << std::endl; 
std::cout << "TEST OPERATOR -- //" << std::endl;
std::cout << std::endl; 
std::cout << a << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;





std::cout << std::endl;
std::cout << "TEST OPERATOR MATH ----/" << std::endl; 
std::cout << std::endl; 

std::cout << "beta = " << beta << "     ";
std::cout << "beta * 2 = " << beta * 2 << "  | ";
std::cout << " 2090 * 2 = " << 2090 * 2 << std::endl;

std::cout << "b = " << b << "     ";
std::cout << "5.05f * 2 = " << 5.05f * 2 << std::endl;


std::cout << "c = " << c << "     ";
std::cout << "5.05f / 2 = " << 5.05f / 2 << std::endl;

std::cout << "d = " << d << "     ";
std::cout << "2 - 5.05f = " << 2 - 5.05f << std::endl;

std::cout << "f = " << f << "     ";
std::cout << "2100 + 5.05f = " << 2100 + 5.05f << std::endl;

std::cout << std::endl;
std::cout << "TEST OPERATOR COMPAR ----/" << std::endl; 
std::cout << " FALSE = 0  | TRUE = 1 "  << std::endl;
std::cout << std::endl;

std::cout << " a = " << a << " b = " << b << std::endl;

std::cout << " a > b = " << (a > b) << std::endl;
std::cout << " a < b = " << (a < b) << std::endl;

std::cout << " f = " << f << " c = " << c << std::endl;
std::cout << " f >= c = " << (f >= c) << std::endl;

std::cout << " f = " << f << " f = " << f << std::endl;
std::cout << " f >= f = " << (f >= f) << std::endl;

std::cout << " f = " << f << " c = " << c << std::endl;
std::cout << " f <= c = " << (f <= c) << std::endl;

std::cout << " c = " << c << " c = " << c << std::endl;
std::cout << " c >= c = " << (c >= c) << std::endl;

std::cout << " f = " << f << " f = " << f << std::endl;
std::cout << " f >= f = " << (f >= f) << std::endl;


std::cout << " f = " << f << " c = " << c << std::endl;
std::cout << " f == c = " << (f == c) << std::endl;

std::cout << " f = " << f << " f = " << f << std::endl;
std::cout << " f == f = " << (f == f) << std::endl;

std::cout << " f = " << f << " f = " << f << std::endl;
std::cout << " f != f = " << (f != f) << std::endl;

std::cout << " c = " << c << " f = " << f << std::endl;
std::cout << " c != f = " << (c != f) << std::endl;



std::cout << std::endl; 
std::cout << "TEST OPERATOR MAX AND MIN ----/" << std::endl; 
std::cout << std::endl; 

std::cout << " max(a, b) --> ";
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << " min(a, b) --> ";
std::cout << Fixed::min( a, b ) << std::endl;

    return 0;
}