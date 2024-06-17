/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:29:16 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 11:31:28 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iomanip>
#include <string>
#include <iostream>

class WrongAnimal
{
    private:
        /* data */
    protected:
        std::string _type;
    public:
        WrongAnimal(/* args */);
        WrongAnimal(std::string const name);
        WrongAnimal(WrongAnimal const & src);
        WrongAnimal &operator=(WrongAnimal const &src);
        virtual ~WrongAnimal();
        std::string const &getType(void)const;
        virtual void makeSound(void)const;
};



#endif