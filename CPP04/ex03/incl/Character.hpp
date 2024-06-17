/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:10:16 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 15:30:30 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character(void);
		Character (std::string const name);
		Character(Character const & src);
		Character &	operator=(Character const & src);
        ~Character(void);
		std::string const &	getName(void) const;
		void				setname(std::string const name);
		
		void				equip(AMateria* m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		void				displayInventory(void) const;
	protected :
		std::string			_name;
		static int const	_inventorySize = 4;
		AMateria *			_inventory[_inventorySize];
		void				_setEmptyInventory(void);
		void				_deleteInventory(void);
};


#endif
