/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:36:00 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/24 16:52:10 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("nameRandom"), _grade(this->_lowExceptiongrade)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade < this->_lowExceptiongrade)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > this->_highExceptiongrade)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
    return ;
}


Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src.getName()), _grade(src.getGrade())
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        this->_name = src.getName();
        this->_grade = src.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int  Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat &rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (os);
}


const char *Bureaucrat::GradeTooHighException::what(void)const
{
    return ("Too high grade");
}

const char *Bureaucrat::GradeTooLowException::what(void)const
{
    return ("Too low grade");
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade < this->_lowExceptiongrade)
        this->_grade += 1;
    else
        throw Bureaucrat::GradeTooLowException();
    return ;
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade > this->_highExceptiongrade)
        this->_grade -= 1;
    else
        throw Bureaucrat::GradeTooHighException();
    return ;
}