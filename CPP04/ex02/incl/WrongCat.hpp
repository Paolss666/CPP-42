/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:53 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 10:36:07 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(WrongCat const & src);
		virtual ~WrongCat(void);

		WrongCat	&	operator=(WrongCat const & src);

		virtual void	makeSound(void) const;
	protected :
};



#endif