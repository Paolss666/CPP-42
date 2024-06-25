/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:18:26 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 15:25:03 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAForm_HPP
#define AAForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string         _name;
		bool				_signed;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
    public:
        AForm();
        AForm(std::string name, const int toGrade, const int toExec);
        AForm(AForm const &src);
        AForm &operator=(AForm const &src);
        virtual ~AForm();
        std::string getName()const ;
        bool        itsSigned()const;
        int         getGradeRequireToSign()const;
        int         getGradeRequireToExec()const;

        void        beSigned(Bureaucrat const &b);
        
        void        execute(Bureaucrat const & executor) const;
        virtual void       doExecution(void) const = 0;
        
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
        class NotSigned: public std::exception
        {
            public:
                virtual const char *what() const throw();  
        };
};

std::ostream &	operator<<(std::ostream & os, AForm const & src);

#endif