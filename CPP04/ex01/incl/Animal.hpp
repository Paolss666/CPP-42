/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:30:37 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/19 12:01:31 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iomanip>
#include <iostream>

/*
Una classe astratta in C++ è una classe che non può essere 
istanziata direttamente e serve come base per altre classi. 
Una classe viene resa astratta includendo almeno una funzione membro pura virtuale. 
Una funzione membro pura virtuale è una funzione dichiarata con la sintassi = 0 
alla fine della dichiarazione.

Caratteristiche delle Classi Astratte
Non istanziabile: Non è possibile creare oggetti di una classe astratta.
Contiene funzioni virtuali pure: Una classe astratta deve contenere almeno una funzione virtuale pura.
Serve come interfaccia: Le classi astratte sono spesso utilizzate per definire un'interfaccia comune che deve essere implementata dalle classi derivate.
*/


class Animal
{
    private:
        /* data */
    protected:
        std::string _type;
    public:
        Animal(/* args */);
        Animal(std::string const name);
        Animal(Animal const & src);
        Animal &operator=(Animal const &src);
        virtual ~Animal();
        std::string const &getType(void)const;
        virtual void makeSound(void)const;

};




#endif
