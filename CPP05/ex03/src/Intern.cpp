/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:21:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/26 13:50:13 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"

/*	on cree un tableau de pointeur sur fonction qui contient 
	trois fonctions appelant chacune le constructeur d'un type 
	de forme avec target en parametre  */



Intern::Intern(void)
{
    typeFt[0] = &Intern::RobotomyRequest;
    typeFt[1] = &Intern::PresidentialPardon;
    typeFt[2] = &Intern::ShrubberyCreation;
    return ;
}

Intern::Intern(Intern const &src)
{
    *this = src;
    return ;
}

Intern::~Intern(void)
{
    std::cout << "Destructor Inter called " << std::endl;
    return ;
}

Intern & Intern::operator=(Intern const &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

AForm   *Intern::ShrubberyCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}


AForm    *Intern::RobotomyRequest(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm    *Intern::PresidentialPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string formName, std::string formTarget)
{
    // if (formName.empty() || formTarget.empty()) {
    //     std::cerr << "Error: formName and formTarget cannot be empty" << std::endl;
    //     return NULL;
    // }
    std::string requests[3] = {"robotomy request", "presidential request", "shrubbery request" };
    for (int i = 0; i < 3; i++)
    {
        if (formName == requests[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*typeFt[i])(formTarget));
        }
    }
    std::cerr << "The form name " << formName << " doesn't exist" << std::endl;
    return NULL;
}

