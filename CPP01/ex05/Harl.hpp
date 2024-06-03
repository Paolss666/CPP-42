/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:56:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/29 10:24:46 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Harl
{
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        typedef void (Harl::*ComplainFt)();
        ComplainFt complains[4];
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
};


#endif