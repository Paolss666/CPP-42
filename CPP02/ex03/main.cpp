/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:37:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/04 17:15:40 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p(2, 2);

    if (bsp(a, b, c, p) == true)
        std::cout << "The point is ------------->>> inside <<<< ------------- " << std::endl;
    else
        std::cout << "The point is ------------->>> outside <<<< ------------- " << std::endl;
    
    Point e(0, 0);
    Point f(5, 0);
    Point g(0, 5);
    Point h_p(5, 0);


    if (bsp(e, f, g, h_p) == true)
        std::cout << "The point is ------------->>> inside <<<< ------------- " << std::endl;
    else
        std::cout << "The point is ------------->>> outside <<<< ------------- " << std::endl;

    return 0;
}

