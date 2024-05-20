/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:38:47 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/20 09:10:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(int ac, char **av)
{
    std::string value;
    Phonebook libray;

    (void)ac;
    (void)av;
    // if (ac > 1
    while (1)
    {
        std::cout << "Enter Rule ";
        if (!std::getline(std::cin, value))
            break;
        if (value == "ADD")
            libray.addContact();
        if (value == "SEARCH")
            libray.searchContact();
        if (value == "EXIT")
            break;
    }
    return 0;
}