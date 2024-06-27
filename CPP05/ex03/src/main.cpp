/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:09:51 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/26 13:50:18 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/Intern.hpp"

int main (void)
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* nonValid;

	std::cout << "-- Making a robotomy request --" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "COCO");
	std::cout << "-- Making a presidential request --" << std::endl;
	ppf = someRandomIntern.makeForm("presidential request", "Maelle");
	std::cout << "-- Making a shrubbery request --" << std::endl;
	scf = someRandomIntern.makeForm("shrubbery request", "Meor");
	std::cout << "-- Making a non valid request --" << std::endl;
	nonValid = someRandomIntern.makeForm("bla bla", "nonValid");
	nonValid = someRandomIntern.makeForm("", "nonValid");

	delete rrf;
	delete ppf;
	delete scf;
	return 0;
}