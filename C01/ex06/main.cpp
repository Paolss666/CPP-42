/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:02:50 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 11:14:30 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Bad numbers of arguments" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(av[1]);
    return 0;
}