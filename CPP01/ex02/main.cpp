/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:34:33 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:05 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

int main(void)
{
    std::string line = "HI THIS IS BRAIN";

    // stringREF ==> une reference sur la string
    std::string& stringREF = line;
    
    // stringPTR ===> un pointeur sur la string
    std::string* stringPTR = &line;


    // l'addresse de la string em memoire
    std::cout << "Addres string in memory: " << &line << std::endl;

    // addresse stock in stringPTR
    std::cout << "addres in stringPTR ===> " << stringPTR << std::endl;
    
    // address stock in stringREF
    std::cout << "addres in stringREF ===> " << &stringREF << std::endl;

    std::cout << "value of string ===> " << line << std::endl;

    std::cout << "value of stringPTR ===> " << *stringPTR << std::endl;

    std::cout << "value of stringREF ===> " << stringREF << std::endl;
}