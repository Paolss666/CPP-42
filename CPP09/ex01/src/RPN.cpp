/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:52:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/10 00:24:19 by npoalett         ###   ########.fr       */
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
            this->_stack.push(std::atoi(value.c_str()));
        else if ((value == "+" || value == "-" || value == "/" || value == "*") && this->_stack.size() > 1)
        {
            vl2 = this->_stack.top();
            this->_stack.pop();
            vl1 = this->_stack.top();
            this->_stack.pop();
            if (value == "+" && (vl1 + vl2 <= 2147483647))
                this->_stack.push(vl1 + vl2);
            else if (value == "-" && (vl1 - vl2 >= -2147483648))
                this->_stack.push(vl1 - vl2);
            else if (value == "*" && (vl1 * vl2 >= -2147483648) && (vl1 * vl2 <= 2147483647))
                this->_stack.push(vl1 * vl2);
            else if (value == "/")
			{
				if (vl2 == 0)
				{
					std::cout << "Error : an operation is a division by 0." << std::endl;
					return ;
				}
				else
					this->_stack.push(vl1 / vl2);
			}
			else
			{
				std::cout << "Error : an operation exceeds int limits." << std::endl;
				return ;
			}
        }
        else
            return (std::cout << "Error : bad input." << std::endl, static_cast<void>(0));
    }
    if (this->_stack.size() != 1)
        std::cout << "Error: bad input." << std::endl;
    else
        std::cout << this->_stack.top() << std::endl;
}

RPN::~RPN()
{return;}

