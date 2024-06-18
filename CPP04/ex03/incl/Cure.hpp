/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:41:33 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/18 19:43:33 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
    		Cure(void);
    		Cure(Cure const & src);
    		~Cure(void);
    
    		Cure &	operator=(Cure const & src);
    
    		Cure*	clone(void) const;
    		void	use(ICharacter& target);
};



#endif