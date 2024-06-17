/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:30:37 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 10:45:50 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iomanip>
#include <iostream>


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
    std::string     *color;

};




#endif
