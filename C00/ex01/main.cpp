/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:38:47 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/15 17:10:53 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    std::string value;
    Phonebook libray;

    while (1)
    {
        std::cout << "Enter Rule ";
        std::getline(std::cin, value);
        if (value == "ADD")
            libray.addContact();
        if (value == "SEARCH")
            libray.searchContact();
        if (value == "EXIT")
            break;
    }
    return 0;
}