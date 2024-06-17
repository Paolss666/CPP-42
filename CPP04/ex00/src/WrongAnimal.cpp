/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:28:47 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 12:17:17 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):_type("WrongAnimal")
{
    std::cout << "WrongAnimal class : Constructor Default called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(std::string const type):_type(type)
{
    std::cout << "WrongAnimal class  : Constructor init called " << std::endl;
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "WrongAnimal class  : Constructor cpy called " << std::endl;
    this->_type = src.getType();
    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal class : Descrutor called " << std::endl;
    return;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << "WrongAnimal class : copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

std::string const & WrongAnimal::getType(void) const 
{
	return this->_type;
}

void	WrongAnimal::makeSound(void) const 
{
    if (this->_type == "WrongCat")
        std::cout << this->_type << " : WRONGMiauuuuooo !!" << std::endl;
    else if (this->_type == "WrongAnimal")
        std::cout << this->_type  << " : Random WrongAnimal sound..." << std::endl;
    return;
}