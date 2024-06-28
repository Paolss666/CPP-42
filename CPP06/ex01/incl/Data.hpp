/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:31:14 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 13:58:20 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <cstdio>
// #include <stdint.h>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <iostream>

class Data
{
    private:
        /* data */
    public:
        Data();
        Data(Data const &src);
        Data &operator=(Data const &src);
        ~Data();
        int nb;
};




#endif