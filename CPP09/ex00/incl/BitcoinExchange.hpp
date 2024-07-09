/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:40:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/09 14:41:01 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE


#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;
        void    _checkDataError(std::string const &data);
        void    _checkValueError(std::string const &value);
        void    _checkSepError(std::string const &sep, std::string const &inp);
        void    _display(std::string const &data, std::string const &value);
    public:
        BitcoinExchange(void);
        BitcoinExchange(const std::map<std::string, float> dbase);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &src);
        const std::map<std::string, float> getBase(void);
        class CouldOpenFile: public std::exception
        {
          public:
              virtual const char *what() const throw();
        };
        class BadImputError: public std::exception
        {
          public:
              virtual const char *what() const throw();
        };
        class NegativeError: public std::exception
        {
          public:
              virtual const char *what() const throw();
        };
        class toBigNumberError: public std::exception
        {
          public:
              virtual const char *what() const throw();
        };
        void    checkAndDisplay(std::string const &inpt);
        ~BitcoinExchange();
};

#endif