/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:18:18 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 11:44:41 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"


Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog class: Default Constructor called" << std::endl;
    return;
}

Dog::Dog(Dog const &src): Animal()
{
    this->_type = src._type;
    std::cout << "Dog class : cpy constructor called" << std::endl;
    return ;
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout << "Dog class : cpy operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog class : Desctructor called" << std::endl;
    return;
}

void    Dog::makeSound(void)const
{
    if (this->_type == "Dog")
        std::cout << this->_type << " : Waof Waof !!" << std::endl;
    else if (this->_type == "Cat")
        std::cout << this->_type << " : Miauuu!!" << std::endl;
    else if (this->_type == "Animal")
        std::cout << this->_type  << " : Random Animal sound..." << std::endl;
    return;
}