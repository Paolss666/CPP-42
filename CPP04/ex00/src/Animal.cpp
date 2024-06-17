/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:35:22 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 11:45:10 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"


Animal::Animal(void):_type("Animal")
{
    std::cout << "Animal class : Constructor Default called" << std::endl;
    return;
}

Animal::Animal(std::string const type):_type(type)
{
    std::cout << "Animal class : Constructor init called " << std::endl;
    return;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal class : Constructor cpy called " << std::endl;
    this->_type = src._type;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal class  : Descrutor called " << std::endl;
    return;
}

Animal &	Animal::operator=(Animal const & src)
{
	std::cout << "Animal class : copy assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const & Animal::getType(void) const 
{
	return this->_type;
}

void	Animal::makeSound(void) const 
{

	if (this->_type == "Dog")
        std::cout << this->_type << " : Waof Waof !!" << std::endl;
    else if (this->_type == "Cat")
        std::cout << this->_type << " : Miauuu!!" << std::endl;
    else if (this->_type == "Animal")
        std::cout << this->_type  << " : Random Animal sound..." << std::endl;
    return;
}