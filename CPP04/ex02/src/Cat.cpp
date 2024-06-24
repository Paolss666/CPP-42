/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:06:07 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/24 16:34:49 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat class: Default Constructor called" << std::endl;
    this->_brain = new Brain();
    return;
}

Cat::Cat(Cat const &src): Animal()
{
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    std::cout << "Cat class : cpy constructor called" << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout << "Cat class : cpy operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        if (this->_brain)
            delete (this->_brain);
        this->_brain = new Brain (*src._brain);
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat class : Desctructor called" << std::endl;
    delete this->_brain;
    return;
}


void    Cat::makeSound(void)const
{
    if (this->_type == "Dog")
        std::cout << this->_type << " : Waof Waof !!" << std::endl;
    else if (this->_type == "Cat")
        std::cout << this->_type << " : Miauuu!!" << std::endl;
    else if (this->_type == "Animal")
        std::cout << this->_type  << " : Random Animal sound..." << std::endl;
    return;
}


Brain * Cat::getBrain(void)const 
{
    return (this->_brain);
}