/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/04 16:23:55 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


/*  
    Les fonctions round retournent une valeur à virgule
    flottante qui représente l'entier le plus proche de x.
    Les valeurs médianes sont arrondies en s’éloignant de zéro,
    indépendamment du paramètre du mode d’arrondi
    à virgule flottante. Il n’y a pas de retour d’erreur.
*/

class Fixed
{
    private:
        int _fixe;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(int const nb); // Costructor intNb fixe;
        Fixed(float const nb); // Costructor float fixe;
        Fixed(const Fixed & src); // Constructor de recopie;
        ~Fixed(void);             // Destructor ;
        float toFloat(void)const; // convertir la valeur en virgule fixe en  nombre flottante;
        int   toInt(void)const; // convertit  la valuer en virgule fixe en nombre entier;
        int getRawBits(void) const ; // retourne la valeur du nombre a virgule fixe sans la convertir;
        void setRawBits(int const raw); // initialise la valeur du nombre a virgule fixe avec celle passee en parametre;
        Fixed operator*( Fixed const & src)const;
        Fixed operator+( Fixed const & src)const;
        Fixed operator-( Fixed const & src)const;
        Fixed operator/( Fixed const & src)const;
        Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
        bool  operator>(Fixed const & src);
        bool  operator<(Fixed const & src);
        bool  operator==(Fixed const & src);
        bool  operator>=(Fixed const & src);
        bool  operator<=(Fixed const & src);
        bool  operator!=(Fixed const & src);
        static Fixed &min(Fixed &src, Fixed &src2);
        static Fixed const &min(Fixed const &src, Fixed const &src2);
        static Fixed &max(Fixed &src, Fixed &src2);
        static Fixed const &max(Fixed const &src, Fixed const &src2);

};

std::ostream & operator<<(std::ostream & os, const Fixed &rhs);

#endif
