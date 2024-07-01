/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tamplete.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/01 16:50:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAMPLETE_HPP
#define TAMPLETE_HPP


#include <iostream>
#include <string>

template<typename T>

void    swap(T &a, T &b)
{
    T   tmp;
    tmp = b;
      
    b = a;
    a = tmp;
    return ;
}

/* Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one */

template<typename T>

T       min(T const &a, T const &b)
{
    if (a < b)
        return (a);
    return b;
}


template<typename T>

T       max(T const &a, T const &b)
{
    if (a > b)
        return (a);
    return b;
}

#endif
