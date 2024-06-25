/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:31:24 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 16:23:51 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("PresidentialPardonForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target("")
{
	return ;
}


PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
AForm(src._target, src._gradeRequiredToSign, src._gradeRequiredToExecute),
_target(src._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called " << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	PresidentialPardonForm::doExecution(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}