/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:09:51 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 16:35:55 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"

int main (void)
{
	std::cout << "--- Creation of the three kind of forms ---"  << std::endl;
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("robot");
	PresidentialPardonForm president("pardon");

	std::cout << "--- Creation of three Bureaucrates ---"  << std::endl;
	Bureaucrat b1("Gagao", 2);
	Bureaucrat b2("Merlou", 149);
	Bureaucrat b3("Maelle", 26);

	std::cout << "--- Sign tests ---"  << std::endl;
	std::cout << " *Gagao shouldn't be able to sign*"  << std::endl;
	b2.signForm(shrubbery);
	std::cout << " *Maelle shouldn't be able to sign*"  << std::endl;
	b3.signForm(president);
	std::cout << " *Maelle incremente by 1*"  << std::endl;
	b3.incrementeGrade();
	std::cout << " *Maelle should be able to sign*"  << std::endl;
	b3.signForm(president);
	std::cout << " *Maelle already signed *"  << std::endl;
	b3.signForm(president);
	std::cout << "--- Signing ---"  << std::endl;
	std::cout << " *Gagao should be able to sign Robotomy*"  << std::endl;
	b1.signForm(robotomy);
	std::cout << " *Maelle should be able to sign Shrubbery*"  << std::endl;
	b3.signForm(shrubbery);
	std::cout << "--- Execution tests ---"  << std::endl;
	std::cout << " *Merlou shouldn't be able to execute President*"  << std::endl;
	b2.executeForm(president);
	std::cout << " *Merlou shouldn't be able to execute Shrubbery*"  << std::endl;
	b2.executeForm(shrubbery);
	std::cout << " *Merlou increment by 147*"  << std::endl;
	for (int i = 0; i < 147; i++)
		b2.incrementeGrade();	
	std::cout << "--- Execution ---"  << std::endl;
	std::cout << " *Merlou should be able to execute President*"  << std::endl;
	b2.executeForm(president);
	std::cout << " *Merlou should be able to execute Robotomy*"  << std::endl;
	b2.executeForm(robotomy);
	std::cout << " *Merlou should be able to execute Robotomy*"  << std::endl;
	b2.executeForm(robotomy);
	std::cout << " *Maelle should be able to execute Robotomy*"  << std::endl;
	b3.executeForm(robotomy);
	std::cout << " *Gagao should be able to execute Shrubbery*"  << std::endl;
	try
	{
		shrubbery.execute(b1);
		std::cout << "Gagao execute Shrubbery" << std::endl ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}