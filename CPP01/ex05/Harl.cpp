/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:59 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 10:36:27 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

/* MESSAGES HARL */

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
    return ; 
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
    return ;
}


void    Harl::error(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return ;
}

void    Harl::warning(void)
{
    std::cout << "his is unacceptable ! I want to speak to the manager now" << std::endl;
    return ;
}



void    Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    this->complains[0] = &Harl::debug;
    
    this->complains[1] = &Harl::info;
    
    this->complains[2] = &Harl::warning;
    
    this->complains[3] = &Harl::error;
    
    for (size_t i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*complains[i])();
            return ;
        }
    }
    std::cerr << "Unknown complain level: " << level << std::endl;
    return;
}
