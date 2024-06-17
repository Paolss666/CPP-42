/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:02:14 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 10:17:58 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/* Ereditarietà Virtuale: 
Viene utilizzata per risolvere problemi di duplicazione 
della classe base comune nell'ereditarietà multipla 
(problema del diamante). 
È dichiarata nella lista di ereditarietà della classe. */

/* Funzioni Virtuali: Consentono la sovrascrittura dei metodi nelle classi derivate 
e permettono il polimorfismo 
dinamico. Dichiarate nelle funzioni membro della classe.
Funzioni Virtuali Pure: Rendono una classe astratta, 
obbligando le classi derivate a implementare le funzioni pure. */

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat const & src);
		virtual ~Cat(void);

		Cat	&	operator=(Cat const & src);

		virtual void	makeSound(void) const;
	protected :

};


#endif