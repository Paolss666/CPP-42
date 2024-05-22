/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:33:39 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/22 17:03:36 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>


Contact::Contact(void){
    return ;
}

Contact::~Contact(void){
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
            std::cerr << "Please enter a valid first Name: ";
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
        return ;
    }
    else
    {
        while (this->isAlpha(lastName) == 0 || lastName.empty())
        {
            std::cerr << "Please enter a valid Last Name: " ;
            if (!std::getline(std::cin, lastName))
                return ;
            if (this->isAlpha(lastName) != 0 && !lastName.empty())
            {
                this->_LastName = lastName;
                break;
            }
        }
    }
    return ;
}

void    Contact::setNickName(std::string nickName)
{
    if (!nickName.empty())
    {
        this->_NickName = nickName;
    }
    else{
        while (nickName.empty())
        {
            std::cerr << "Please enter a valid Nick Name: " ;
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
    if (this->isNumber(numberPhone) != 0 && !numberPhone.empty() && this->isValidNumber(numberPhone))
    {
        this->_PhoneNumber = numberPhone;
        return ;
    }
    else
    {
        while (this->isNumber(numberPhone) == 0 || numberPhone.empty() || !this->isValidNumber(numberPhone))
        {
            std::cerr << "Please enter a valid phone number: " ;
            if (!std::getline(std::cin, numberPhone))
                return ;
            if (this->isNumber(numberPhone) != 0 && !numberPhone.empty() && this->isValidNumber(numberPhone))
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
    }
    else
    {
        while (DarkSecret.empty())
        {
            std::cerr << "Please enter a valid DARK secret: " ;
            if (std::getline(std::cin, DarkSecret))
                return ;
            if (!DarkSecret.empty())
            {
                this->_DarkSecret = DarkSecret;
                break;
            }
        }
    }
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

bool    Contact::isValid(void) const {
        return !this->_FirstName.empty() && !this->_LastName.empty();
}


int     Contact::isValidNumber(std::string const number){
    
    if (number.size() < 4)
        return 0;
    return 1;
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
