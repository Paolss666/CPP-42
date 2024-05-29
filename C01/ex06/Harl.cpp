/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:59:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 11:13:55 by npaolett         ###   ########.fr       */
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

int Harl::levelIndex(const std::string& level){
    if(level == "DEBUG") return 0;
    if(level == "INFO") return 1;
    if(level == "WARNING") return 2;
    if(level == "ERROR") return 3;
    return -1;
}

void    Harl::complain(std::string level)
{
    
    this->complains[0] = &Harl::debug;
    
    this->complains[1] = &Harl::info;
    
    this->complains[2] = &Harl::warning;
    
    this->complains[3] = &Harl::error;
    
    int getLevelIndex = levelIndex(level);

    switch (getLevelIndex)
    {
        case 0:
            (this->*complains[0])();
            break;
        case 1:
            (this->*complains[1])();
            break;
        case 2:
            (this->*complains[2])();
            break;
        case 3:
            (this->*complains[3])();
            break;
        case -1:
            std::cerr << "Unknown complain level: " << level << std::endl;
            break;
    }
    return;
}