/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/20 15:39:11 by npaolett         ###   ########.fr       */
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
    std::cout << "|-----    LastName   -----|" << std::endl;
    std::cout << "          ";
    if (!std::getline(std::cin, lastName))
        return ;
    contact.setLastName(lastName);
    std::cout << "|------  NickName   ------|" << std::endl;
    std::cout << "         ";
    if (!std::getline(std::cin, nickName))
        return ;
    contact.setNickName(nickName);
    std::cout << "|----   PhoneNumber   ----|" << std::endl;
    std::cout << "        ";
    if (!std::getline(std::cin, PhoneNumber))
        return ;
    contact.setPhoneNumber(PhoneNumber);
    std::cout << "|----   Darksecret    ----|" << std::endl;
    std::cout << "        ";
    if (!std::getline(std::cin, darkSecret))
        return ;
    contact.setDarkSecret(darkSecret);

    this->_idx++;
    this->_contacts[this->_idx] = contact;
    return ;
}


void		Phonebook::setPrintContact(std::string const line)
{
    if (line.size() >= 10)
        std::cout << line.substr(0, 9) << "." << std ::setw (10);
    else
        std::cout << line << std ::setw (10);
    std::cout << std::endl;
}

void    Phonebook::searchContact(void)
{
    Contact     contact;
    std::string valueToFound;
    int     index_to_found = 0;
    int     fnd = 0;

    while (this->_idx2 <=  this->_idx)
    {
        std::cout << "index contact " << this->_idx2 << std::endl;
        setPrintContact(this->_contacts[fnd].getFirstName());
        setPrintContact(this->_contacts[fnd].getLastName());
        setPrintContact(this->_contacts[fnd].getNickName());
        this->_idx2++;
    }
    // std::cout << "---> index_2" << this->_idx2 << std::endl;
    // std::cout << "---> index" << this->_idx << std::endl;

    std::cout << "Enter index of the conctact ";
	if (this->isNumber(valueToFound) != 0 && !valueToFound.empty())
        index_to_found = std::stoi(valueToFound);
    else{
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
    
    if (this->_idx2 == -1)
    {
        std::cerr << "The PhoneBook is empty, please add a contact" << std::endl;
		this->_idx2 = 0;
        // this->_idx = -1;
        // fnd = 0;
        return ;
    }
	else if (this->_idx2 < index_to_found || index_to_found < 0)
	{
		std::cerr << "Index value is bigger than the Phonebook " << std::endl;
		this->_idx2 = 0;
        // this->_idx = -1;
        // index_to_found = 0;
        // fnd = 0;
        return ;
	}
    std::cout << "index found " << index_to_found << std::endl;
    
    while(fnd <= index_to_found)
    {
        if (fnd == index_to_found)
        {
            setPrintContact(this->_contacts[fnd].getFirstName());
            setPrintContact(this->_contacts[fnd].getLastName());
            setPrintContact(this->_contacts[fnd].getNickName());
            setPrintContact(this->_contacts[fnd].getNumberPhone());
            setPrintContact(this->_contacts[fnd].getDarkSecret());
        }
        fnd++;
    }
    fnd = 0;
    this->_idx2 = 0;
    // this->_idx = -1;
    return ;
}