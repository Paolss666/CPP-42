/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:33:39 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/20 14:54:43 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>


Contact::Contact(void){
    // std::cout << "Constructor called" << std::endl;
    return ;
}

Contact::~Contact(void){
    // std::cout << "Destructor called" << std::endl;
    return ;
}


// ----------------------   SET REQUETE -------------------- // 


void    Contact::setFirstName(std::string FirstName)
{
    if (this->isAlpha(FirstName) != 0 && !FirstName.empty())
    {
        this->_FirstName= FirstName;
        return ;
    }
    else
    {
        while (this->isAlpha(FirstName) == 0 || FirstName.empty())
        {
            std::cerr << "Please enter a valid first Name: " << std::endl;
            if (!std::getline(std::cin, FirstName))
                return ;
            if (this->isAlpha(FirstName) != 0 && !FirstName.empty())
            {
                this->_FirstName = FirstName;
                break;
            }
        }
    }
    return ;
}

void    Contact::setLastName(std::string lastName)
{
    if (this->isAlpha(lastName) != 0 && !lastName.empty())
    {
        this->_LastName= lastName;
        // std::cout << "lastName set ->" << _LastName << std::endl;
        return ;
    }
    else
    {
        while (this->isAlpha(lastName) == 0 || lastName.empty())
        {
            std::cerr << "Please enter a valid Last Name: " << std::endl;
            if (!std::getline(std::cin, lastName))
                return ;
            if (this->isAlpha(lastName) != 0 && !lastName.empty())
            {
                this->_LastName = lastName;
                break;
            }
        }
    }
    // std::cerr << "WRONG LastName" << std::endl;
    return ;
}

void    Contact::setNickName(std::string nickName)
{
    if (!nickName.empty())
    {
        this->_NickName = nickName;
        // std::cout << "nickName set ->" << _NickName <<std::endl;
    }
    else{
        while (nickName.empty())
        {
            std::cerr << "Please enter a valid Nick Name: " << std::endl;
            if (!std::getline(std::cin, nickName))
                return ;
            if (!nickName.empty())
            {
                this->_NickName = nickName;
                break;
            }
        }
    }
}

void    Contact::setPhoneNumber(std::string numberPhone)
{
    if (this->isNumber(numberPhone) != 0 && !numberPhone.empty())
    {
        this->_PhoneNumber = numberPhone;
        // std::cout << "_PhoneNumber set ->" << _PhoneNumber <<std::endl;
        return ;
    }
    else
    {
        while (this->isNumber(numberPhone) == 0 || numberPhone.empty())
        {
            std::cerr << "Please enter a valid phone number: " << std::endl;
            if (!std::getline(std::cin, numberPhone))
                return ;
            if (this->isNumber(numberPhone) != 0 && !numberPhone.empty())
            {
                this->_PhoneNumber = numberPhone;
                break;
            }
        }
    }
    return ;
}

void    Contact::setDarkSecret(std::string DarkSecret)
{
    if (!DarkSecret.empty())
    {
        this->_DarkSecret = DarkSecret;
        std::cout << "_DarkSecret  ->" << _DarkSecret <<std::endl;
    }
    else
    {
        while (DarkSecret.empty())
        {
            std::cerr << "Please enter a valid DARK secret: " << std::endl;
            if (std::getline(std::cin, DarkSecret))
                return ;
            if (!DarkSecret.empty())
            {
                this->_DarkSecret = DarkSecret;
                break;
            }
        }
    }
    // this->_DarkSecret = DarkSecret;
    // std::cout << "Darcksecret set ->" << _DarkSecret << std::endl;
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

    while (j < str.size() )
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
