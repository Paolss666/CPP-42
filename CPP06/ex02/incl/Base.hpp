/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:52:30 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 15:53:50 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


#include <iomanip>
#include <string>
#include <stdexcept>
#include <iostream>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Base
{
    public:
        virtual ~Base();
};


Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif
