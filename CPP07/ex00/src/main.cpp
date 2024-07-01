/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:20:42 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/01 16:55:42 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/whatever.hpp"


int main( void ) {
    
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout <<  std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    std::cout <<  std::endl;

    double f = 2.0000343434;
    double l = -3.0040;
    ::swap( f, l  );
    std::cout << "f = " << f << ", l = " << l << std::endl;
    std::cout << "min( f, l ) = " << ::min( f, l ) << std::endl;
    std::cout << "max( f, l ) = " << ::max( f, l ) << std::endl;
    return 0;
}