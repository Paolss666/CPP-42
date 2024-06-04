/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:12:37 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/04 16:29:23 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _y;
        Fixed const _x;
    public:
        Point(/* args */);
        Point(float const x, float const y);
        Point(const Point & src); 
        Point & operator=(Point const & src);
        ~Point();
        Fixed const  getFixedX(void) const ;
        Fixed const  getFixedY(void) const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

