/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:29 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/09 18:19:44 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <fstream>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(RPN const &src);
        RPN &operator=(RPN const &src);
        void    checkAndDo(std::string const &inpt);
        ~RPN();
};



#endif