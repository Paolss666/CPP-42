/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:37:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/05 17:11:48 by npaolett         ###   ########.fr       */
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

    std::cout << " a = (0, 0); b = (5, 0); c = (0, 5) ---> point (2, 2) -> IS INSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";

    if (bsp(a, b, c, p) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    Point a_ins(0, 0);
    Point b_ins(10.10f, 0);
    Point c_ins(0, 10.10f);
    Point p_ins(8.08f, 0.08f);

    std::cout << " a = (0, 0); b = (10.10f, 0); c = (0, 10.10f) ---> point (8.08f, 0.08f) -> IS INSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";

    if (bsp(a_ins, b_ins, c_ins, p_ins) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;

    Point at(0, 0);
    Point bt(5, 0);
    Point ct(0, 5);
    Point pt(4, 4);

    std::cout << " at = (0, 0); bt = (5, 0); ct = (0, 5) ---> point (4, 4) -> IS OUTSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";

    if (bsp(at, bt, ct, pt) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    Point e(0, 0);
    Point f(5, 0);
    Point g(0, 5);
    Point h_p(5, 0);

    std::cout << " a = (0, 0); b = (5, 0); c = (0, 5) ---> point (5, 0) -> IS OUTSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";
    
    if (bsp(e, f, g, h_p) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;
    
    std::cout <<  std::endl;
    std::cout <<  std::endl;

    Point e_t(0, 0);
    Point f_t(5, 0);
    Point g_t(0, 5);
    Point h_p_t(0, 0);

    std::cout << " a = (0, 0); b = (5, 0); c = (0, 5) ---> point (0, 0) -> IS OUTSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";
    
    if (bsp(e_t, f_t, g_t, h_p_t) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;
    
    std::cout <<  std::endl;
    std::cout <<  std::endl;
    
    Point e_te(0, 0);
    Point f_te(5, 0);
    Point g_te(0, 5);
    Point h_p_te(0, 5);

    std::cout << " a = (0, 0); b = (5, 0); c = (0, 5) ---> point (0, 5) -> IS OUTSIDE --|" << std::endl;
    std::cout << "TEST WITH ALGO BSP ";
    
    if (bsp(e_te, f_te, g_te, h_p_te) == true)
        std::cout << "---->>> inside <<<---- " << std::endl;
    else
        std::cout << "---->>> outside <<<---- " << std::endl;

    return 0;
}

