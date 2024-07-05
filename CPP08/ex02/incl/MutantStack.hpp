/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:55:15 by npoalett          #+#    #+#             */
/*   Updated: 2024/07/05 12:10:43 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>

#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <iterator>

template<typename T>

class MutantStack: public std::stack<T>
{
    private:
    
    public: 
        MutantStack(void){return;}
        MutantStack(MutantStack const &src){*this = src;}
        ~MutantStack(void){ return ;}
        MutantStack &operator=(MutantStack const &src)
        {
            if (this != &src)
                *this = src;
            return (*this);
        }
        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin(){return this->c.begin();}
        iterator end(){return this->c.end();}

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin(){return this->c.rbegin();}
        reverse_iterator rend(){return this->c.rend();} 
};

#endif