/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:06:07 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 11:44:56 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat class: Default Constructor called" << std::endl;
    return;
}

Cat::Cat(Cat const &src): Animal()
{
    this->_type = src._type;
    std::cout << "Cat class : cpy constructor called" << std::endl;
    return ;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout << "Cat class : cpy operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat class : Desctructor called" << std::endl;
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