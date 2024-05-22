/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/22 18:45:40 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

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
    if (!std::getline(std::cin, firstName))
        return ;
    contact.setFirstName(firstName);
    
    std::cout << "|-----   LastName   -----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, lastName))
        return ;
    contact.setLastName(lastName);
    
    std::cout << "|------  NickName   ------|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, nickName))
        return ;
    contact.setNickName(nickName);
    
    std::cout << "|----    PhoneNumber   ----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, PhoneNumber))
        return ;
    contact.setPhoneNumber(PhoneNumber);
    
    std::cout << "|----    Darksecret    ----|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, darkSecret))
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
    if (line.size() > 10)
        std::cout << std::setw (10) << line.substr(0, 9) << ".";
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
    
    for(int i = 0; i < 8 && this->_contacts[i].isValid() ; i++)
    {   
        // std::cout << "  index  | FIRNAME | LASTNAME |  NICKNAME |" << std::endl;
        std::cout  << "    |INDEX|    " << std ::setw (10);
        std::cout  << "    |FIRNAME|    " << std ::setw (10);
        std::cout  << "    |LASTNAME|    " << std ::setw (10);
        std::cout  << "    |NICKNAME|    " << std ::setw (10) ;
        std::cout << std::endl;
        setPrintContact(std::to_string(i));
        // std::cout << " | " ;
        setPrintContact(this->_contacts[i].getFirstName());
        // std::cout << " | " ;
        setPrintContact(this->_contacts[i].getLastName());
        // std::cout << " | " ;
        setPrintContact(this->_contacts[i].getNickName());
        // std::cout << " | " ;
        std::cout << std::endl;
    }

    std::cout << "Enter index of the conctact ";
	if (this->isNumber(valueToFound) != 0 && !valueToFound.empty())
        index_to_found = std::stoi(valueToFound);
    else {
        while (this->isNumber(valueToFound) == 0 || valueToFound.empty()){
            std::cerr << "Please enter a valid index: ";
            if (!std::getline(std::cin, valueToFound))
                return ;
            if (this->isNumber(valueToFound) != 0 && !valueToFound.empty())
            {
                index_to_found = std::stoi(valueToFound);
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
            setPrintContact(this->_contacts[i].getFirstName());
            setPrintContact(this->_contacts[i].getLastName());
            setPrintContact(this->_contacts[i].getNickName());
            setPrintContact(this->_contacts[i].getNumberPhone());
            setPrintContact(this->_contacts[i].getDarkSecret());
            std::cout << std::endl;
        }
    }
    return ;
}