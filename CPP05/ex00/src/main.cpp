/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:09:51 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 12:14:39 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"


void    TestBureaucrat(std::string name, int grade)
{
    try
    {
        Bureaucrat buro(name, grade);
        std::cout << buro << std::endl;
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
	std::cout << std::endl << "*** Bureaucrat test with name and grade initialization constructor ***" << std::endl;
	{
		TestBureaucrat("Gagao", 15);
		TestBureaucrat("Mimi", 70);
		TestBureaucrat("B0b0", -8);
		TestBureaucrat("Nico", 180);
	}
	std::cout << std::endl << "*** Bureaucrat test copy constructor ***" << std::endl;
	{
		Bureaucrat b("Jolie", 45);
		std::cout << " Bureaucrat is " << b << std::endl;
		Bureaucrat bCopy(b);
		std::cout << " Bureaucrat is " << bCopy << std::endl;

	}
	std::cout << std::endl << "*** Bureaucrat test copy assignement ***" << std::endl;
	{
		Bureaucrat b("Mimi", 64);
		Bureaucrat bCopy;
		std::cout << " Bureaucrat is " << b << std::endl;
		std::cout << " Bureaucrat is " << bCopy << std::endl;
		bCopy = b;
		std::cout << " Bureaucrat is " << bCopy << std::endl;
	}
	std::cout << std::endl << "*** Bureaucrat test with incrementation and decrementation ***" << std::endl;
	{	
		std::cout << "-- Testing limite min --" << std::endl;
		Bureaucrat bMax("Momo", 147);
		try 
		{
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
			std::cout << "Decrementing the grade by 1, grade should be : " << bMax.getGrade() + 1 << std::endl;
			bMax.decrementeGrade();
			std::cout << bMax << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception : " << e.what() << std::endl;
		}
	
		std::cout << "-- Testing limite max --" << std::endl;
		Bureaucrat bMin("Momo", 2);
		try 
		{
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
			std::cout << "Incrementing the grade by 1, grade should be : " << bMin.getGrade() - 1 << std::endl;
			bMin.incrementeGrade();
			std::cout << bMin << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception : " << e.what() << std::endl;
		}
	
	}

	return 0;
}