/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/23 16:28:33 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

Phonebook::Phonebook(void)
{
    this->_idx = -1;
    this->_idx2 = 0;
    return ;
}

Phonebook::~Phonebook(void)
{
    return ;
}

int     Phonebook::isNumber(std::string const str)
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

void    Phonebook::addContact(void)
{
    Contact contact;
    
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string PhoneNumber;
    std::string darkSecret;
    
    std::cout << "|---- ENTER A CONTACT ----|" << std::endl;
    std::cout << " "<< std::endl;
    
    std::cout << "|----    FirstName   -----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, firstName)|| std::cin.eof())
        return ;
    contact.setFirstName(firstName);
    
    std::cout << "|-----   LastName   -----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, lastName)|| std::cin.eof())
        return ;
    contact.setLastName(lastName);
    
    std::cout << "|------  NickName   ------|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, nickName)|| std::cin.eof())
        return ;
    contact.setNickName(nickName);
    
    std::cout << "|----    PhoneNumber   ----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, PhoneNumber)|| std::cin.eof())
        return ;
    contact.setPhoneNumber(PhoneNumber);
    
    std::cout << "|----    Darksecret    ----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, darkSecret)|| std::cin.eof())
        return ;
    contact.setDarkSecret(darkSecret);
    
    if (this->_idx == 7)
    {
        std::cout << "mon index est dans la condifiton a " << this->_idx << std::endl;
        this->_contacts[this->_idx2] = contact;
        if (this->_idx2 == 7)
            return (this->_idx = -1, this->_idx2 = 0, (void)0);
        this->_idx2++;
        return ;
    }
    this->_idx++;
    this->_contacts[this->_idx] = contact;
    return ;
}


void		Phonebook::setPrintContact(std::string const line)
{
    if (line.size() > 9)
        std::cout << std::setw (10) << line.substr(0, 9) + ".";
    else
        std::cout << std ::setw (10) << line ;
    return ;
}

void    Phonebook::searchContact(void)
{
    Contact         contact;
    std::string     valueToFound;
    int             index_to_found = 0;


    if (!this->_contacts[0].isValid())
    {
        std::cerr << "The PhoneBook is empty, please add a contact" << std::endl;
        return ;
    }
    std::cout << std::endl << "╔══════════╦══════════╦══════════╦══════════╗" << std::endl
						                << "║   INDEX  ║FIRST NAME║LAST  NAME║ NICKNAME ║" << std::endl;
    for(int i = 0; i < 8 && this->_contacts[i].isValid() ; i++)
    {   
        std::cout << "|" ;
        std::cout << std ::setw (10) << i;
        std::cout << "|" ;
        setPrintContact(this->_contacts[i].getFirstName());
        std::cout << "|" ;
        setPrintContact(this->_contacts[i].getLastName());
        std::cout << "|" ;
        setPrintContact(this->_contacts[i].getNickName());
        std::cout << "|" ;
        std::cout << std::endl;
    }

    std::cout << "Enter index of the conctact ";
	if (this->isNumber(valueToFound) != 0 && !valueToFound.empty())
        index_to_found = atoi(valueToFound.c_str());
    else {
        while (this->isNumber(valueToFound) == 0 || valueToFound.empty()){
            std::cerr << "Please enter a valid index: ";
            if (!std::getline(std::cin, valueToFound)|| std::cin.eof())
                return ;
            if (this->isNumber(valueToFound) != 0 && !valueToFound.empty())
            {
                index_to_found = atoi(valueToFound.c_str());
                break;
            }
        }
    }
	if (!this->_contacts[index_to_found].isValid() || index_to_found > 7)
	{
		std::cerr << "Index value is bigger than the numbers of contacts " << std::endl;
        return ;
	}
    
    for(int i = 0; i < 8 && this->_contacts[i].isValid() ; i++)
    {
        if (i == index_to_found)
        {
            std::cout << "FirstName: " <<  this->_contacts[i].getFirstName();
            std::cout << std::endl;
            std::cout << "LastName: " << this->_contacts[i].getLastName();
            std::cout << std::endl;
            std::cout << "NickName: " << this->_contacts[i].getNickName();
            std::cout << std::endl;
            std::cout << "NumberPhone: " << this->_contacts[i].getNumberPhone();
            std::cout << std::endl;
            std::cout << "DarkSecret: " << this->_contacts[i].getDarkSecret();
            std::cout << std::endl;
        }
    }
    return ;
}