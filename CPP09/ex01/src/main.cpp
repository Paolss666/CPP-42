/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 00:18:04 by npoalett          #+#    #+#             */
/*   Updated: 2024/07/10 00:18:27 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn;

		std::string input(argv[1]);
		rpn.checkAndDo(input.c_str());
	}
	else
		std::cout << "Error : invalid number of arguments" << std::endl;
	return (0);
}