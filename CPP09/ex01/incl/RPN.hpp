/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:46:29 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/10 00:21:21 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cctype>
# include <cstdlib>

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