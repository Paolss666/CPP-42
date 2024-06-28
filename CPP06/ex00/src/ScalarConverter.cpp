/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:14:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 11:49:40 by npaolett         ###   ########.fr       */
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
    if (str.size() == 1)
    {
        if (str[0] >= 0 && str[0] <= 127)
            return (true);
    }
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


int     dataType(const std::string &str)
{
    if (isInt(str)) return 0;
    if (isChar(str)) return 1;
    if (isDouble(str)) return 2;
    if (isFloat(str)) return 3;
    if (isPseudoLim(str)) return 4;
    return 5;
}
void	printFromInt(std::string str)
{
	int	nb;
	std::istringstream stream(str);
	stream >> nb;	

	if ((nb >= 0 && nb < 32) || nb == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (nb >= 32 && nb <= 126)
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}


void	printFromChar(std::string str)
{
	std::cout << "char: '" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}


void printFromFloat(std::string str)
{
    float	nbf;
	
	std::istringstream streamf(str.erase(str.size() - 1));
	streamf >> nbf;
    
	// std::cout << "nbf = " <<  nbf << std::endl;

	if (nbf < 32 || nbf > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbf) << "'" << std::endl;

	if (nbf >= static_cast<float>(std::numeric_limits<int>::min()) && nbf < static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: " << static_cast<int>(nbf) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (nbf == static_cast<int>(nbf))
		std::cout << "float: " << nbf << ".0f" << std::endl;
	else
		std::cout << "float: " << nbf << "f" << std::endl;

	if (nbf == static_cast<int>(nbf))
		std::cout << "double: " << nbf << ".0" << std::endl;
	else
		std::cout << "double: " << nbf << std::endl;
    
}

void    printFromDouble(std::string str)
{
    double	nbd;
	
	std::istringstream streamf(str.erase(str.size() - 1));
	streamf >> nbd;

	if (nbd < 32 || nbd > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbd) << "'" << std::endl;

	if(nbd < static_cast<long>(std::numeric_limits<int>::min()) || nbd > static_cast<long>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else 
		std::cout << "int: " << static_cast<int>(nbd) << std::endl;

    if (nbd < -static_cast<double>(std::numeric_limits<float>::max()) || nbd > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else if (static_cast<float>(nbd) == static_cast<int>(nbd))
		std::cout << "float: " << static_cast<float>(nbd) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(nbd) << "f" << std::endl;

	if (nbd == static_cast<int>(nbd))
		std::cout << "double: " << nbd << ".0" << std::endl;
	else
		std::cout << "double: " << nbd << std::endl;
}

void    printLim(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.erase(str.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	return ;

}

void    impossibleConv(void)
{
    std::cout << "char: impossible" <<std::endl;
    std::cout << "int: impossible" <<std::endl;
    std::cout << "float: impossible" <<std::endl;
    std::cout << "doule: impossible" <<std::endl;
}

void ScalarConverter::converter(std::string const src)
{
    int type = dataType(src);
    switch (type)
    {
        case 0:
            printFromInt(src);
            break;
        case 1:
            printFromChar(src);       
            break;
        case 2:
            printFromDouble(src);
            break;
        case 3:
            printFromFloat(src);      
            break;
        case 4:
            printLim(src);  
            break;
        default:
            impossibleConv();       
            break;
    }
    return ;
}