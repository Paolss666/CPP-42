/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:35:48 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 16:17:00 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): 
AForm("RobotomyRequestForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute), 
_target("")
{
	return ;
}

/**** Constructor with target initialization ****/
RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", this->_gradeRequiredToSign, this->_gradeRequiredToExecute),
_target(target)
{
	return ;
}

/**** Copy constructor *****/
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
AForm(src._target, src._gradeRequiredToSign, src._gradeRequiredToExecute)
{
	this->_target = src._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called " << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::doExecution(void) const
{
	std::cout << "VRRRRRRRRRRRRvvvvvvvvVVVRRRRRRRRRRRRRR" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "The robotomy failed..." << std::endl;
	return ;
}