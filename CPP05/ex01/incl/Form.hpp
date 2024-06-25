/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:18:26 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 16:26:50 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string         _name;
		bool				_signed;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
    public:
        Form();
        Form(std::string name, const int toGrade, const int toExec);
        Form(Form const &src);
        Form &operator=(Form const &src);
        virtual ~Form();
        std::string getName()const ;
        bool        itsSigned()const;
        int         getGradeRequireToSign()const;
        int         getGradeRequireToExec()const;
        void        beSigned(Bureaucrat const &b);
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        class AlreadySigned: public std::exception
        {
            public: 
                virtual const char *what() const throw();
        };
        
};

std::ostream &	operator<<(std::ostream & os, Form const & src);

#endif