/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:18 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 14:48:42 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"

Form::Form():
_name("GenericName"),
_signed(false), 
_gradeRequiredToSign(Bureaucrat::_lowExceptiongrade),
_gradeRequiredToExecute(Bureaucrat::_lowExceptiongrade)
{
    return ;
}
Form::Form(std::string name, const int toGrade, const int toExec): _name(name), _signed(false), _gradeRequiredToSign(toGrade), _gradeRequiredToExecute(toExec)
{
    if (toGrade < Bureaucrat::_highExceptiongrade || toExec < Bureaucrat::_highExceptiongrade)
        throw Bureaucrat::GradeTooHighException();
    else if (toGrade > Bureaucrat::_lowExceptiongrade || toExec > Bureaucrat::_lowExceptiongrade) 
        throw Bureaucrat::GradeTooHighException();
    return ;
}

Form::Form(Form const &src):_name(src._name), _signed(src._signed),
 _gradeRequiredToSign(src.getGradeRequireToSign()),
 _gradeRequiredToExecute(src.getGradeRequireToExec())
{
    return ;
}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
        this->_signed = src._signed;
    return (*this);
}

std::string Form::getName() const
{
    return (this->_name);
}


int Form::getGradeRequireToExec()const
{
    return (this->_gradeRequiredToExecute);
}


int Form::getGradeRequireToSign()const
{
    return (this->_gradeRequiredToSign);
}

bool    Form::itsSigned()const
{
    return (this->_signed);
}


Form::~Form()
{
    return ;
}


const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high !");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low !");
}

const char *Form::AlreadySigned::what(void) const throw()
{
	return ("already signed !");
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (this->_signed)
        throw Form::AlreadySigned();
    else if (b.getGrade() <= this->_gradeRequiredToSign)
        this->_signed = true;
    else 
        throw Form::GradeTooLowException();
    return ;
}


/**** << operator ****/
std::ostream &	operator<<(std::ostream & os, Form const & src)
{
	os << src.getName() << " [" << (src.itsSigned() ? "signed" : "unsigned" ) << ", to sign:" << src.getGradeRequireToSign()
	<< ", to execute:" << src.getGradeRequireToExec()  << "]";
	return os;
}


