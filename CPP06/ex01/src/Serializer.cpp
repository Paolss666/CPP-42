/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:40:06 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 16:10:23 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"


Serializer::Serializer()
{
    return;
}

Serializer::Serializer(Serializer const &src)
{
    *this = src;
    return ;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    if (this != &src)
        *this = src;
    return (*this);
}

Serializer::~Serializer()
{
    return;
}

/* 
reinterpret_cast  
Il permet des conversions de type qui sont généralement plus risquées que celles effectuées 
par static_cast. Ce type de conversion est principalement utilisé pour convertir 
des types de pointeurs de manière non sûre,
où le type résultant peut ne pas avoir de relation avec le type original.
 */

uintptr_t Serializer::serialize(Data *ptr)
{
    if(ptr)
    {
        uintptr_t   value;
        value = reinterpret_cast<uintptr_t>(ptr);
        return (value);
    }
    std::cerr << "ptr is null" << std::endl;
    return 0;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *st;
    if (raw)
    {
        st = reinterpret_cast<Data *>(raw);
        return (st);
    }
    std::cerr << "raw is null" << std::endl;
    return NULL;
}