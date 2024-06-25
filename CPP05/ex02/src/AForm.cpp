/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:18 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 14:48:42 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"

AForm::AForm():
_name("GenericName"),
_signed(false), 
_gradeRequiredToSign(Bureaucrat::_lowExceptiongrade),
_gradeRequiredToExecute(Bureaucrat::_lowExceptiongrade)
{
    return ;
}
AForm::AForm(std::string name, const int toGrade, const int toExec): _name(name), _signed(false), _gradeRequiredToSign(toGrade), _gradeRequiredToExecute(toExec)
{
    if (toGrade < Bureaucrat::_highExceptiongrade || toExec < Bureaucrat::_highExceptiongrade)
        throw Bureaucrat::GradeTooHighException();
    else if (toGrade > Bureaucrat::_lowExceptiongrade || toExec > Bureaucrat::_lowExceptiongrade) 
        throw Bureaucrat::GradeTooHighException();
    return ;
}

AForm::AForm(AForm const &src):_name(src._name), _signed(src._signed),
 _gradeRequiredToSign(src.getGradeRequireToSign()),
 _gradeRequiredToExecute(src.getGradeRequireToExec())
{
    return ;
}

AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
        this->_signed = src._signed;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->_name);
}


int AForm::getGradeRequireToExec()const
{
    return (this->_gradeRequiredToExecute);
}


int AForm::getGradeRequireToSign()const
{
    return (this->_gradeRequiredToSign);
}

bool    AForm::itsSigned()const
{
    return (this->_signed);
}


AForm::~AForm()
{
    return ;
}


const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade too high !");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade too low !");
}

const char *AForm::AlreadySigned::what(void) const throw()
{
	return ("already signed !");
}


const char *AForm::NotSigned::what(void) const throw()
{
    return ("not signed !");
}


void    AForm::beSigned(Bureaucrat const &b)
{
    if (this->_signed)
        throw AForm::AlreadySigned();
    else if (b.getGrade() <= this->_gradeRequiredToSign)
        this->_signed = true;
    else 
        throw AForm::GradeTooLowException();
    return ;
}

void    AForm::execute(Bureaucrat const & executer)const
{
    if (!this->itsSigned())
        throw AForm::NotSigned();
    else if (this->itsSigned() && executer.getGrade() <= this->_gradeRequiredToExecute)
        this->doExecution();
    else
        throw AForm::GradeTooLowException();
    return ;
}

/**** << operator ****/
std::ostream &	operator<<(std::ostream & os, AForm const & src)
{
	os << src.getName() << " [" << (src.itsSigned() ? "signed" : "unsigned" ) << ", to sign:" << src.getGradeRequireToSign()
	<< ", to execute:" << src.getGradeRequireToExec()  << "]";
	return os;
}


