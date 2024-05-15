/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:21:12 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/09 18:43:23 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale> // std::toupper

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    else
    {
        for(int i = 1; i < ac; i++)
        {
            std::string string(av[i]);
            for(size_t j = 0; j < string.size(); j++)
                std::cout << (char) toupper(string[j]);
        }
        std::cout << std::endl;
    }
    return 0;
}