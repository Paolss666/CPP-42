/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:00 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 12:01:06 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain(void)
{
    std::cout << " Brain class: Constructor default called" << std::endl;
}

Brain::Brain(Brain const &src)
{
    std::cout << " Brain class:  cpy Constructor  called" << std::endl;
    *this = src;
}


Brain & Brain::operator=(Brain const &src)
{
    std::cout << " Brain class:  operator  called" << std::endl;
    if (this != &src)
        for(int i = 0; i < nb_ideas; i++)
            this->_ideas[i] = src._ideas[i];
    return (*this);
}


void    Brain::setIdeas(int i, std::string const &idea)
{
    if (i >= 0 && i <= 100)
        this->_ideas[i] = idea;
    else
        std::cout << "The index has to be between 0 and 100" << std::endl;
    return;
}

std::string const Brain::getIdea(int i)const
{
    if (i >= 0 && i <= 100)
        return (_ideas[i]);
    std::cout << "The index has to be between 0 and 100" << std::endl;
    return (NULL);
}


Brain::~Brain(void)
{
    std::cout << " Brain class:  Destructor  called" << std::endl;
    return;
}

