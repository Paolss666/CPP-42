/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:40:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/08 15:32:44 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE


#include <vector>
#include <map>
#include <iostream>
#include <string>


class BitcoinExchange
{
    private:
        const std::map<std::string, float> _db;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const std::map<std::string, float> dbase);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &src);
        const std::map<std::string, float> getBase(void);
        void    setBase(const std::map<std::string, float> db);
        bool    checkData(std::string const &src);
        ~BitcoinExchange();
};

void    printValeur();

#endif