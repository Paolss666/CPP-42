/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:55:52 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/18 19:34:11 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource(/* args */);
        MateriaSource(std::string const name);
        MateriaSource(MateriaSource const & src);
        ~MateriaSource();
        MateriaSource   &operator=(MateriaSource const &src);
        void            learnMateria(AMateria *materia);
        AMateria        *createMateria(std::string const &type);
        void			_setEmptyInventory(void);
		void			_deleteInventory(void);
	protected :
		std::string			_name;
		static int const	_inventorySize = 4;
		AMateria *			_sInventory[_inventorySize];
};



#endif