/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:18:18 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/24 16:35:02 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"


Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog class: Default Constructor called" << std::endl;
    this->_brain = new Brain();
    return;
}

Dog::Dog(Dog const &src): Animal()
{
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    std::cout << "Dog class : cpy constructor called" << std::endl;
    return ;
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout << "Dog class : cpy operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        if (this->_brain)
            delete (this->_brain);
        this->_brain = new Brain (*src._brain);
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog class : Desctructor called" << std::endl;
    delete this->_brain;
    return;
}


void    Dog::makeSound(void)const
{
    if (this->_type == "Dog")
        std::cout << this->_type << " : Waof Waof !!" << std::endl;
    else if (this->_type == "Dog")
        std::cout << this->_type << " : Miauuu!!" << std::endl;
    else if (this->_type == "Animal")
        std::cout << this->_type  << " : Random Animal sound..." << std::endl;
    return;
}

Brain * Dog::getBrain(void)const 
{
    return (this->_brain);
}