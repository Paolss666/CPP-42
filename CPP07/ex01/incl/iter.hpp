/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/03 11:45:25 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


// template<typename L>



template<typename T>

int   sizeArray(T array[])
{
    int i = 0;
    while(array[i])
        i++;
    return i;
}

template <typename U>

void    printFt(U &n)
{
    std::cout << n << std::endl;
}

template <typename T, typename U>

void	iter(T * arrayAdd, int len, void(*f)(U &)) 
{
	for (int i = 0; i < len; i++)
		f(arrayAdd[i]);
}

#endif