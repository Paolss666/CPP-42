/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:58:15 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/22 16:44:50 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class Phonebook
{
    public:
		Phonebook();
		~Phonebook();
		void    addContact(void);
		void    searchContact(void);
	private :
		Contact     _contacts[8];
		int			_idx;
		int			_idx2;
		void		setPrintContact(std::string const line);
		int           isNumber(std::string const str);
};

#endif