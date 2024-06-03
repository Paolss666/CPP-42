/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:59:02 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 11:28:34 by npaolett         ###   ########.fr       */
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
    std::cout <<std::endl;
    std::cout << "[DEBUG]" <<std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
    return ; 
}

void    Harl::info(void)
{
    std::cout <<std::endl;
    std::cout << "[INFO]" <<std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
    return ;
}


void    Harl::error(void)
{
    std::cout <<std::endl;
    std::cout << "[ERROR]" <<std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return ;
}

void    Harl::warning(void)
{
    std::cout <<std::endl;
    std::cout << "[WARNING]" <<std::endl;
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
            for (size_t i = getLevelIndex; i < 4; i++)
                    (this->*complains[i])();
            break;
        case 1:
            for (size_t i = getLevelIndex; i < 4; i++)
                    (this->*complains[i])();
            break;
        case 2:
            for (size_t i = getLevelIndex; i < 4; i++)
                    (this->*complains[i])();
            break;
        case 3:
            for (size_t i = getLevelIndex; i < 4; i++)
                    (this->*complains[i])();
            break;
        case -1:
            std::cerr << "[ Probably complaining about insignificant problems ]" << level << std::endl;
            break;
    }
    return;
}