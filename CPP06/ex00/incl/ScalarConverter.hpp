/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:11:03 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/27 16:25:18 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter(/* args */);
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();
    public:
        static void converter(std::string const src);        
};

bool    isChar(std::string  str);
bool    isInt(std::string str);
bool    isFloat(std::string str);
bool    isDouble(std::string str);
bool	isPseudoLim(std::string str);



#endif