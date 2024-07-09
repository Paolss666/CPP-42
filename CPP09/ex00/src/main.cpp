/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:01 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/09 14:41:14 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            
            BitcoinExchange     btc;
            std::string     text = av[1];
            std::ifstream   is(text.c_str());
            
            if (!is)
                return (std::cerr << "Error: can't open fail " << std::endl, 1);
            
            std::string inpt;

            int flag = 0;
            while (getline(is,inpt))
            {
                if ((inpt == "date | value") && !flag)
                    getline(is, inpt);
                flag = 1;
                if (!inpt.empty())
                    btc.checkAndDisplay(inpt);
                else
                    std::cerr << "Error: bad input => emmpty line" << std::endl;
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }    
    }
    else
        std::cerr << "Error: Bad Arguments" << std::endl;
    
}