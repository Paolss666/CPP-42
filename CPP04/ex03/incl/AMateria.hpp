/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:49:43 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 13:51:43 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>
#include <string>


class ICharacter;

class AMateria
{
    protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &amateria);
		AMateria &	operator=(AMateria const & materia);
		virtual ~AMateria(void);


		std::string const &	getType() const; //Returns the materia type
		virtual 			AMateria* clone() const = 0;
		virtual void 		use(ICharacter& target);

};




#endif
