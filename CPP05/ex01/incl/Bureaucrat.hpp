/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:21 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 14:57:01 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP 

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "../incl/Form.hpp"

class Form;
class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    public:
        static const int       _lowExceptiongrade = 150;
        static const int       _highExceptiongrade = 1;
        Bureaucrat(/* args */);
        Bureaucrat(std::string name, int grade); 
        Bureaucrat(Bureaucrat const &src); 
        Bureaucrat &operator=(Bureaucrat const &src);
        ~Bureaucrat();
        class GradeTooHighException: public std::exception
        {
            public: 
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public: 
                virtual const char *what() const throw();
        };
		void	signForm(Form &form) const;
        std::string getName() const;
        int     getGrade() const;
        void    incrementeGrade();
        void    decrementeGrade();
        

};

std::ostream & operator<<(std::ostream & os, Bureaucrat const &rhs);


#endif
 
