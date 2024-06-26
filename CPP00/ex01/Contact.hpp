/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:10:09 by npaolett          #+#    #+#             */
/*   Updated: 2024/05/23 16:29:22 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <string>

class Contact
{
    public:
        Contact();
        ~Contact();
        void          setFirstName(std::string FirstName);
        void          setLastName(std::string lastName);
        void          setNickName(std::string nickName);
        void          setPhoneNumber(std::string phoneNumber);
        void          setDarkSecret(std::string darckSercret);
		bool          isValid(void) const;
        std::string   getFirstName(void);
		std::string	  getLastName(void);
		std::string	  getNumberPhone(void);
		std::string	  getNickName(void);
        std::string   getDarkSecret(void);
    private :
        std::string  _FirstName;
        std::string  _LastName;
        std::string  _NickName;
        std::string  _PhoneNumber;
		std::string  _DarkSecret;
		int           isNumber(std::string const str);
		int           isValidNumber(std::string const str);
        int           isAlpha(std::string const str);
};


#endif
