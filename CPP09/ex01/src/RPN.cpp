/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:52:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/09 18:24:10 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"

RPN::RPN(void)
{return;}

RPN::RPN(RPN const &src):_stack(src._stack)
{
    return ;
}

RPN &RPN::operator=(RPN const &src)
{
    if (this != &src)
        this->_stack = src._stack;
    return (*this);
}

void    RPN::checkAndDo(std::string const &inpt)
{
    std::string value;
    std::istringstream  is(inpt);

    long    vl1;
    long    vl2;
    while (is >> value)
    {
        if (std::isdigit(value[0]) && value.length() == 1)
            _stack.push(std::atoi(value.c_str()));
    }
}

RPN::~RPN()
{return;}

