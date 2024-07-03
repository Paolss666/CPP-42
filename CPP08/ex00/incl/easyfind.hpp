/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:42:21 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/03 16:17:40 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stdexcept>


template<typename T>
typename std::list<T>::const_iterator easyfind(const std::list<T> &tofind, int n)
{
    typename std::list<T>::const_iterator found = std::find(tofind.begin(), tofind.end(), n);
    
    if (found == tofind.end())
        throw   std::runtime_error("Element not found");

    return found;
}


#endif