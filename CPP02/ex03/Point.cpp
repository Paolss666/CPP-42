/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:36:53 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/05 14:21:19 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _y(0), _x(0)
{
    return;
}

Point::Point(float const x, float const y): _y(y), _x(x)
{
    return ;
}

Point::Point(const Point & src):  _y(src.getFixedY()), _x(src.getFixedX())
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}


Point & Point::operator=(Point const & src)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    (void)src;
    return (*this);
}

Point::~Point()
{
    return ;
}


Fixed const Point::getFixedX(void) const
{
    return (this->_x);
}


Fixed const Point::getFixedY(void) const
{
    return (this->_y);
}

