/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:52:51 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/18 19:54:08 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
    		Ice(void);
    		Ice(Ice const & src);
    		~Ice(void);
    
    		Ice &	operator=(Ice const & src);
    
    		Ice*	clone(void) const;
    		void	use(ICharacter& target);
};


#endif