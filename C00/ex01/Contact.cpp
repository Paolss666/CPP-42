/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:33:39 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/15 16:27:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>


Contact::Contact(void){
    std::cout << "Constructor called" << std::endl;
    return ;
}

Contact::~Contact(void){
    std::cout << "Destructor called" << std::endl;
    return ;
}


// ----------------------   SET REQUETE -------------------- // 


void    Contact::setFirstName(std::string FirstName)
{
    if (this->isAlpha(FirstName) != 0)
    {
        this->_FirstName = FirstName;
        std::cout << "firstName set ->" << _FirstName << std::endl;
        return ;
    }
    std::cerr << "WRONG FirstName" << std::endl;
    return ;
}

void    Contact::setLastName(std::string lastName)
{
    if (this->isAlpha(lastName) != 0)
    {
        this->_LastName= lastName;
        std::cout << "lastName set ->" << _LastName << std::endl;
        return ;
    }
    std::cerr << "WRONG LastName" << std::endl;
    return ;
}

void    Contact::setNickName(std::string nickName)
{
    this->_NickName = nickName;
    std::cout << "nickName set ->" << _NickName <<std::endl;
}

void    Contact::setPhoneNumber(std::string numberPhone)
{
    if (this->isNumber(numberPhone) != 0)
    {
        this->_PhoneNumber = numberPhone;
        std::cout << "_PhoneNumber set ->" << _PhoneNumber <<std::endl;
        return ;
    }
    std::cout << "Isn't a number" <<std::endl;
    return ;
}

void    Contact::setDarkSecret(std::string DarkSecret)
{
    this->_DarkSecret = DarkSecret;
    std::cout << "Darcksecret set ->" << _DarkSecret << std::endl;
    return ;
}

// ----------------------   GET REQUETE -------------------- // 

std::string   Contact::getNumberPhone(void)
{
    return(this->_PhoneNumber);
}

std::string   Contact::getNickName(void)
{
    return(this->_NickName);
}

std::string    Contact::getFirstName(void)
{
    return(this->_FirstName);
}

std::string  Contact::getLastName(void)
{
    return(this->_LastName);
}

std::string  Contact::getDarkSecret(void)
{
    return(this->_DarkSecret);
}

int     Contact::isNumber(std::string const str)
{
    size_t j = 0;

    while (j < str.size())
    {
        if (str[j] >= '0' && str[j] <= '9')
            j++;
        else
            return 0;
    }
    return 1;
}

int     Contact::isAlpha(std::string const str)
{
    size_t j = 0;

    while (j < str.size())
    {
        if (((str[j] >= 'a' && str[j] <= 'z') || str[j] == ' ') || ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] == ' ')))
            j++;
        else
            return 0;
    }
    return 1;
}
