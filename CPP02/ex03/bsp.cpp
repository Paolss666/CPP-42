/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:04:04 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/05 16:54:00 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/* 
La façon la plus simple de déterminer si un point se trouve à 
l’intérieur d’un triangle est de vérifier le nombre de points 
dans l’ enveloppe convexe des sommets du triangle adjacents au point en question.
Si la coque a trois pointes, la pointe se trouve à l'intérieur du triangle;
si c'est quatre, il se trouve en dehors du triangle.
Pour déterminer si un point donné vse trouve à l’intérieur d’un triangle donné,
considérons un sommet individuel, noté v_0, et soit v_1et v_2 soient les vecteurs de v_0 
vers les deux autres sommets.
Exprimer le vecteur de v_0 à ven termes de v_1 et v_2 donne alors

v = v_0 + av_1 + bv_2,

(2)
alpah 	= 	(det(v v_2)- det(v_0 v_2))/(det(v_1 v_2)) 	

(3)

beta 	= 	-(det(v v_1)-det(v_0 v_1))/(det(v_1 v_2)), 	

où

det(uv)= u * v = u_x * v_y - u_y * v_x // il determinante puo essere utilizzato
                                        oer calcolare l'area del parallgrm di due vettori
                                        o per determinare se tre punti son coll.

 */


Fixed det(Point const &u, Point const &v)
{    
    return ((u.getFixedX() * v.getFixedY()) - (u.getFixedY() * v.getFixedX()));
}

//  &v = point v0 = a v1 = b v2 = c

// det(v1, v0) - det(v1, v)) / det(v1, v2)

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed a_x = a.getFixedX() - point.getFixedX();
    Fixed a_y = a.getFixedY() - point.getFixedY();

    Fixed b_x = b.getFixedX() - point.getFixedX();
    Fixed b_y = b.getFixedY() - point.getFixedY();

    Fixed c_x = c.getFixedX() - point.getFixedX();
    Fixed c_y = c.getFixedY() - point.getFixedY();

    if ((a_y == 0 && a_x == 0) || (b_y == 0 && b_x == 0) || (c_y == 0 && c_x == 0))
        return false;
    
    Fixed determ = det(b, c);
    if ( determ == 0)
        return false;

    //  Fixed alpha = (v2_x * v1_y - v2_y * v1_x) / det_v0_v1;
    // Fixed beta = (v0_x * v2_y - v0_y * v2_x) / det_v0_v1;

    Fixed    alpha = (a.getFixedX() * (c.getFixedY() - a.getFixedY()) + ((point.getFixedY() - a.getFixedY()) * (c.getFixedX() - a.getFixedX())) - point.getFixedX() * (c.getFixedY() - a.getFixedY())) / (((b.getFixedY() - a.getFixedY()) * (c.getFixedX() - a.getFixedX())) - (((b.getFixedX() - a.getFixedX()) * (c.getFixedY() - a.getFixedY()))));
    Fixed    beta = (point.getFixedY() - a.getFixedY() - alpha * (b.getFixedY() - a.getFixedY())) / c.getFixedY() - a.getFixedY();

    // std::cout << "beta = " << beta << std::endl;
    // std::cout << "alpha = " << alpha << std::endl;
    
    
    return (alpha >= 0 && beta >= 0 && (alpha + beta) <= 1);
}