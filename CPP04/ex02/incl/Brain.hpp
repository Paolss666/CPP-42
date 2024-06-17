/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:51:43 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/17 12:26:13 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>


class Brain
{
	public :
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain	&	operator=(Brain const & src);

		void				setIdeas(int i, std::string const & idea);
		std::string const	getIdea(int i) const;

		static int const	nb_ideas = 100;
	private :
		std::string	_ideas[100];
};





#endif