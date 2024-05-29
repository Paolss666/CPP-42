/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:20:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 10:35:53 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    // std::string level;
    Harl    harl;
    // while (1)
    // {
    //     std::cout << "Enter Message: ";
    //     if (!getline(std::cin,level))
    //         return 1;
    //     harl.complain(level);
    //     if (level == "exit")
    //         break;
    // }
    // return 0;

    std::cout << "Test with Debug: " << std::endl;
    harl.complain("DEBUG");
    std::cout << "Test with Info: " << std::endl;
    harl.complain("INFO");
    std::cout << "Test with Warning: " << std::endl;
    harl.complain("WARNING");
    std::cout << "Test with Error: " << std::endl;
    harl.complain("ERROR");
    std::cout << "Test with Enknown: " << std::endl;
    harl.complain("UNKNOWN");

}