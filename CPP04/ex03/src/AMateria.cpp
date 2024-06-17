/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:53:28 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 13:59:38 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AMateria.hpp"

AMateria::AMateria(void)
{
    return;
}

AMateria::AMateria(std::string const &type):_type(type)
{
    return;
}

AMateria::AMateria(AMateria const &materia)
{
    static_cast<void>(materia);
    return;
}

AMateria & AMateria::operator=(AMateria const &materia)
{
    static_cast<void>(materia);
    return(*this);
}

AMateria::~AMateria(void)
{
    return;
}

std::string const & AMateria::getType()const
{
    return this->_type;
}

void    AMateria::use(ICharacter &target)
{
    std::cout << target.getName() << std::endl;
    return ;
}
