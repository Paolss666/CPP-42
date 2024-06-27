/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:57:22 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/27 15:07:22 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "BAD ARGUMENTS" << std::endl, 1);
    ScalarConverter::converter(av[1]);
    return 0;
}