/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:30:37 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/19 12:04:22 by npaolett         ###   ########.fr       */
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
        virtual void makeSound(void)const = 0;
};

#endif
