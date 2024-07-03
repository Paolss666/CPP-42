/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:27:45 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/03 17:32:14 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>


template<typename N> 

class Span
{
    private:
        int _array[N];
    public:
        Span();
        Span();
        Span(Span const &src);
        Span &operator=(Span const &src);
        ~Span();
};



#endif