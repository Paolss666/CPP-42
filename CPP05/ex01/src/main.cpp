/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:09:51 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 14:52:32 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"


void    TestForm(std::string name, int toSigne, int toExec)
{
    try
    {
        Form fo(name, toSigne, toExec);
        std::cout << fo << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
        
}

int main(void)
{
	std::cout << std::endl << "*** Bureaucrat test with default constructor ***" << std::endl;
	{
		Bureaucrat	b;
		std::cout << "Default bureaucrat is: " << b << std::endl;
	}
	std::cout << std::endl << "*** Form test with name and grade initialization constructor ***" << std::endl;
	{
		TestForm("Gagao", 15, 15);
		TestForm("Mimi", 70, 70);
		TestForm("B0b0", -8, 0);
		TestForm("Nico", 2, 180);
	}
	std::cout << std::endl << "*** test Burocrat and Form ***" << std::endl;
		Form f1("Average form", 75, 75);
		Form f2("Easy form", 140, 140);
		Form f3("Hard form", 10, 10);

		Bureaucrat b1("Gagao", 20);
		Bureaucrat b2("Momo", 142);
		Bureaucrat b3("Mimi", 10);

		std::cout << std::endl;
		b1.signForm(f1);
		std::cout << std::endl;
		b1.signForm(f1);
		std::cout << std::endl;
		b1.signForm(f3);
		std::cout << std::endl;
		b2.signForm(f2);
		std::cout << std::endl;
		b3.signForm(f3);
		std::cout << std::endl;
	return 0;
}