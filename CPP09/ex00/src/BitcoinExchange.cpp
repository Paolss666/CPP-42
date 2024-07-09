/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:13 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/09 14:52:37 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::string const filname("data.csv");
    std::string data;
    std::string value;

    float       fvalue;
    std::ifstream   isfile(filname.c_str());

    if (isfile)
    {
        getline(isfile, data);
        while (std::getline(isfile, data, ','))
        {
            std::getline(isfile, value);
            std::istringstream isfiles(value);
            isfiles >> fvalue;
            this->_db[data] = fvalue;
        }
    }
    else
        throw BitcoinExchange::CouldOpenFile();
    return;
}

void    BitcoinExchange::_checkDataError(std::string const &data)
{
    int year, month, day;
    
    if (data.empty() || data.size() != 10)
        throw BitcoinExchange::BadImputError();
    
    if (data[4] != '-' || data[7] != '-')
        throw BitcoinExchange::BadImputError();
    
    std::istringstream  is(data);
    
    is >> year;
    if (year < 2009 || year > 2022)
        throw BitcoinExchange::BadImputError();
    
    is.ignore();

    is >> month;
    if (month < 1 || month > 12)
        throw BitcoinExchange::BadImputError();
    
    is.ignore();

    is >> day;
    if (day < 1 || day > 32)
        throw BitcoinExchange::BadImputError();
    if (year == 2009 && month == 1 && day < 2)
        throw BitcoinExchange::BadImputError();
    if (year > 2022 || (year == 2022 && month > 3) || (year == 2022 && month == 3 && day > 29))
        throw BitcoinExchange::BadImputError();
    if ((month == 4 ||  month == 6 || month == 9 || month == 11 ) && day == 31)
        throw BitcoinExchange::BadImputError();
    if (month == 2 && day > 28)
    {
        if (day > 29)
            throw BitcoinExchange::BadImputError();
        else if (day == 29 && (year % 4) != 0)
            throw BitcoinExchange::BadImputError();
    }
}


void    BitcoinExchange::_checkValueError(std::string const &value)
{
    int i = 0;
    if (value.empty())
        throw BitcoinExchange::BadImputError();
    
    if (!std::isdigit(value[i]) && value[i] != '-')
        throw BitcoinExchange::BadImputError();
    
    if (value[i] == '-')
    {
        if (value[i + 1])
            i++;
        else
            throw BitcoinExchange::BadImputError();
    }
    
    while (value[i] && value[i] != '.')
    {
        if (value[i] < '0' || value[i] > '9')
            throw BitcoinExchange::BadImputError();
        i++;
    }
    if (value[i] && value[i] == '.')
    {
        if (value[i + 1])
            i++;
        else
            throw BitcoinExchange::BadImputError();
        while (value[i])
        {
            if (value[i] < '0' || value[i] > '9')
                throw BitcoinExchange::BadImputError();
            i++;
        }
    }
    
    float   fvalue;
    std::istringstream  is(value);

    is >> fvalue;
    if (is.fail())
    {
        if (fvalue == std::numeric_limits<float>::infinity())
            throw BitcoinExchange::BadImputError();
        if (fvalue == -std::numeric_limits<float>::infinity())
            throw BitcoinExchange::BadImputError();
    }
    if (fvalue < 0)
        throw BitcoinExchange::NegativeError();
    if (fvalue > 1000)
        throw BitcoinExchange::toBigNumberError();
}

void BitcoinExchange::_display(std::string const &data, std::string const &value)
{
    float   fvalue;
    std::istringstream  is(value);
    is >> fvalue;

    std::map<std::string, float>::const_iterator it = this->_db.upper_bound(data);
    if (it->first != data && it != _db.begin())
        it--;
    std::cout << data << " => " << value << " = " << it->second * fvalue << std::endl;
}

void    BitcoinExchange::_checkSepError(std::string const &sep, std::string const &inp)
{
    int space = 0;

    for (std::size_t i = 0; i < inp.size(); ++i)
    {
        if (inp[i] == ' ')
            space++;
    }
    if (space != 2 || sep != "|")
        throw BitcoinExchange::BadImputError();
        
}

void    BitcoinExchange::checkAndDisplay(std::string const &inpt)
{
    std::string date,sep,value;
    std::istringstream  is(inpt);

    is >> date >> sep >> value;
    try
    {
        _checkDataError(date);
        _checkValueError(value);
        _checkSepError(sep, inpt);
        _display(date, value);
    }
    catch(BitcoinExchange::BitcoinExchange::BadImputError &e)
    {
        std::cerr << e.what() << inpt << std::endl;
    }
    catch(BitcoinExchange::BitcoinExchange::NegativeError &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(BitcoinExchange::BitcoinExchange::toBigNumberError &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const std::map<std::string, float> dbase):_db(dbase)
{
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    this->_db = src._db;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
        this->_db = src._db;
    return (*this);
}

const std::map<std::string, float> BitcoinExchange::getBase()
{
    return (this->_db);
}

const char *BitcoinExchange::CouldOpenFile::what() const throw()
{
    return ("Error: could not open file.");
}

const char *BitcoinExchange::BadImputError::what() const throw()
{
    return ("Error: bad input => ");
}


const char *BitcoinExchange::NegativeError::what() const throw()
{
    return ("Error: not a positive number.");
}

const char *BitcoinExchange::toBigNumberError::what() const throw()
{
    return ("Error: too large a number.");
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}