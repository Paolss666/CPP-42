/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:36:00 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 14:57:36 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("nameRandom"), _grade(this->_lowExceptiongrade)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < this->_highExceptiongrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > this->_lowExceptiongrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

void	Bureaucrat::signForm(Form &form) const
{
	try {
		form.beSigned(*this);
		std::cout << *this << " signed" << form << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}


Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src._name), _grade(src._grade)
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        // this->_name = src._name;
        this->_grade = src._grade;
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


const char *Bureaucrat::GradeTooHighException::what(void)const throw()
{
    return ("Too high grade");
}

const char *Bureaucrat::GradeTooLowException::what(void)const throw()
{
    return ("Too low grade");
}

void	Bureaucrat::incrementeGrade(void)
{
	if (this->_grade > this->_highExceptiongrade)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void	Bureaucrat::decrementeGrade(void)
{
	if (this->_grade < this->_lowExceptiongrade)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
	return ;
}