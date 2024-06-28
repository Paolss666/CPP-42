/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:35:09 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 14:22:02 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Data.hpp"

Data::Data(void)
{
    return ;
}

Data::Data(Data const &src)
{
    if (this != &src)
        *this = src;
    return ;
}


Data &Data::operator=(Data const &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

Data::~Data()
{
    return ;
}