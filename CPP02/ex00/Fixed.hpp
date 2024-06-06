/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/06 10:59:07 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>


class Fixed
{
    private:
        int _fixe;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(Fixed & src); // Constructor de recopie;
        Fixed & operator=(Fixed const & src);
        ~Fixed(void);
        int getRawBits(void) const ; // retourne la valeur du nombre a virgule fixe sans la convertir;
        void setRawBits(int const raw); // initialise la valeur du nombre a virgule fixe avec celle passee en parametre;
};


#endif