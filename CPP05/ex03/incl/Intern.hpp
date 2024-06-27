/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:48:41 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/26 13:50:32 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        typedef AForm *(Intern::*ft)(std::string target);
        ft typeFt[3];
    public:
        Intern(/* args */);
        Intern(Intern const &src);
        ~Intern();
		Intern & operator=(Intern const & src);
        AForm   *ShrubberyCreation(std::string target);
        AForm   *RobotomyRequest(std::string target);
        AForm   *PresidentialPardon(std::string target);

        AForm    *makeForm(std::string formName, std::string formTarget);
        // AForm   *makeForm(const char *formName, const char *formTarget);

};



#endif