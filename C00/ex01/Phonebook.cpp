/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:31 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/15 18:09:19 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook(void)
{
    std::cout << "Constructor called" << std::endl;
    this->_idx = 0;
    this->_idx2 = 0;
    return ;
}

Phonebook::~Phonebook(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void    Phonebook::addContact(void)
{
    Contact contact;
    
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string PhoneNumber;
    std::string darkSecret;

    std::cout << "firstName ----------------- " << std::endl;
    std::getline(std::cin, firstName);
    std::cout << "lastName ----------------- " << std::endl;
    std::getline(std::cin, lastName);
    std::cout << "nickName ----------------- " << std::endl;
    std::getline(std::cin, nickName);
    std::cout << "PhoneNumber ----------------- " << std::endl;
    std::getline(std::cin, PhoneNumber);
    std::cout << "Darksecret ----------------- " << std::endl;
    std::getline(std::cin, darkSecret);

    contact.setFirstName(firstName);
    contact.setLastName(lastName);
    contact.setNickName(nickName);
    contact.setPhoneNumber(PhoneNumber);
    contact.setDarkSecret(darkSecret);

    this->_contacts[this->_idx] = contact;
    this->_idx++;
    std::cout << "--> contact contact.getFirstName() --> " << contact.getFirstName() << std::endl;
    std::cout << "--> contact contact.getLastName() --> " << contact.getLastName() << std::endl;
    std::cout << "--> contact contact.getNickName --> " << contact.getNickName() << std::endl;
    std::cout << "--> contact contact.getNumberPhone() --> " << contact.getNumberPhone() << std::endl;
    std::cout << "--> contact contact.getDarkSecret() --> " << contact.getDarkSecret() << std::endl;
    std::cout << "--> index contact  -->  " << _idx << std::endl;
    return ;
}

void    Phonebook::searchContact(void)
{
    Contact     contact;
    std::string valueToFound;
    int     index_to_found;

    while (this->_idx2 <  this->_idx)
    {
        std::cout << "index contact " << this->_idx2 << std::endl;
        std::cout << this->_contacts[this->_idx2].getFirstName() << std::endl;
        std::cout << this->_contacts[this->_idx2].getLastName() << std::endl;
        std::cout << this->_contacts[this->_idx2].getNickName() << std::endl;
        this->_idx2++;
    }

    std::cout << "Enter index of the conctact ";
    std::getline(std::cin, valueToFound);
    index_to_found = std::stoi(valueToFound);

    std::cout << "index found " << index_to_found << std::endl;

    return ;
}