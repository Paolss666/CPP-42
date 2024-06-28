/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:23:28 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 13:53:58 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <stdint.h>
// #include <cstdint>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include "Data.hpp"

// class Data;

class Serializer
{
    private:
        Serializer(/* args */);
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        ~Serializer();
        /* data */
    public:
        static uintptr_t   serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif