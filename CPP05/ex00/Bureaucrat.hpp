/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:17:21 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/24 16:50:12 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP 

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

class Bureaucrat
{
    private:
        std::string const _name;
        int               _grade;
        static const int       _lowExceptiongrade = 1;
        static const int       _highExceptiongrade = 150;
    public:
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
        std::string getName() const;
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat &rhs);


#endif
 
