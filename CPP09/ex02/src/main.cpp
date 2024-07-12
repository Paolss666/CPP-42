/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:08:19 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/12 16:44:25 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

int main(int ac, char **av)
{
if (ac > 2)
	{
		PmergeMe JF;
		try
		{
			JF.ToStartJF(ac, av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout << "Bad numbers of arguments" << std::endl;
    return 0;
}