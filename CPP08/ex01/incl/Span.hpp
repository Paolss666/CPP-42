/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:27:45 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/05 10:55:04 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iomanip>
#include <iostream>


#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <string>
#include <iterator>

class Span
{
    private:
        unsigned int    N;
        std::vector<int>    array;
    public:
        Span();
        Span(unsigned int N);
        Span(Span const &src);
        Span &operator=(Span const &src);
        ~Span();

        void    addNumber(int nb);
        
        int     shortestSpan();
        
        int     longestSpan();

        void    addNumberSpan(std::vector<int> toAdd);
        
        void       printSpan(void);

        /* exception */
        class fullArray: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class emptyArray: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class noDistanceFound: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

};



#endif