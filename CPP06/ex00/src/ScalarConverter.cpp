/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:14:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/27 16:26:57 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"



ScalarConverter::ScalarConverter()
{
    return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &src)
{
    static_cast<void>(src);
    // *this = src;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    return ;
}



bool    isChar(std::string const str)
{
    if (str.length() == 1)
        if (str[0] >= 0 && str[0] <= 127)
            return (true);
    return (false);
}

bool    isInt(std::string const str)
{
    int i = 0;
    int     nb = 0;
    long int nblong = 0;

    if (str[i] == '-' || str[i] == '-')
        i++;
    if (!str[i])
        return false;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
        /* Dopo il tentativo di lettura, .fail() verifica se la lettura è fallita.
        Se la lettura del valore int fallisce, 
        significa che la stringa non contiene un numero int 
        valido, 
        e quindi la funzione restituisce false */
    std::istringstream sstream(str);
    std::istringstream fstream(str);
    if ((sstream >> nblong).fail())
        return (false);
    fstream >> nblong;
     if (nblong < -std::numeric_limits<float>::max() || nblong > std::numeric_limits<float>::max())
       return (false);
    return (true);
}

bool    isFloat(std::string str)
{
    int i = 0;
    int         check = 0;
    float        nbfloat;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return false;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != 'f')
            return false;
        if (str[i] == '.')
            check++;
        if (check > 1) 
            return false;       
        if (str[i] == 'f' && str[i + 1] != '\0')
            return false;
        i++;
    }
    std::istringstream  fstream(str.erase(str.size() - 1));
    if ((fstream >> nbfloat).fail())
        return false;
    if (nbfloat < -std::numeric_limits<float>::max() || nbfloat > std::numeric_limits<float>::max())
       return (false);
    return (true);
}

bool    isDouble(std::string str)
{
    int i = 0;
    int         check = 0;
    double        nbdouble;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return false;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            return false;
        if (str[i] == '.')
            check++;
        if (check > 1) 
            return false;
        i++;
    }
    std::istringstream  fstream(str.erase(str.size() - 1));
    if ((fstream >> nbdouble).fail())
        return false;
    if (nbdouble < -std::numeric_limits<double>::max() || nbdouble > std::numeric_limits<double>::max())
       return (false);
    return (true);
}

bool	isPseudoLim(std::string str)
{
	std::string p[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (p[i] == str)
			return (true);
	}
	return (false);
}


static int     dataType(const std::string &str)
{
    if (isChar(str)) return 0;
    if (isInt(str)) return 1;
    if (isDouble(str)) return 2;
    if (isFloat(str)) return 3;
    if (isPseudoLim(str)) return 4;
    return 5;
}

void ScalarConverter::converter(std::string const src)
{
    int type = dataType(src);
    std::cout << type << std::endl;
    switch (type)
    {
        case 0:
            std::cout << "CHAR"  << std::endl;       
            break;
        case 1:
            std::cout << "INT"  << std::endl;       
            break;
        case 2:
            std::cout << "DOUBLE"  << std::endl;
            break;
        case 3:
            std::cout << "FLOAT"  << std::endl;       
            break;
        case 4:
            std::cout << "LIM"  << std::endl;       
            break;
        default:
            std::cout << "booh"  << std::endl;       
            break;
    }
    return ;
}