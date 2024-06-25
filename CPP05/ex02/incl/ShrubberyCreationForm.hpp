/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:33:17 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/25 16:21:48 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERYCREATIONFORM_HPP
#define SHRUBERYCREATIONFORM_HPP 


#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
		
		void	doExecution(void) const;

	protected :
		static const int			_gradeRequiredToSign = 145;
		static const int			_gradeRequiredToExecute = 137;
		std::string					_target;
		static const std::string	_shrubbery;
		static const std::string	_shrubbery2;
};



#endif