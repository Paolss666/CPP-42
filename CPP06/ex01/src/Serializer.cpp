/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:40:06 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 14:20:55 by npaolett         ###   ########.fr       */
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