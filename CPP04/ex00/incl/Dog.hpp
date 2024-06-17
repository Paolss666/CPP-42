/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:12:27 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 10:22:03 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

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


class Dog:  public Animal
{
    protected:
        /* data */
    public:
    		Dog(void);
    		Dog(Dog const & src);
    		virtual ~Dog(void);
    
    		Dog	&	operator=(Dog const & src);
    
    		virtual void	makeSound(void) const;
};

#endif

