/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:55:15 by npoalett          #+#    #+#             */
/*   Updated: 2024/07/06 15:26:08 by npoalett         ###   ########.fr       */
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
#include <deque>

/* type name U = std::deque<T>, se non viene definito allora prende come valore
    prefedifino C sara considerato come std::deque<T>  */

template<typename T, typename U = std::deque<T> >

class MutantStack: public std::stack<T, U>
{
	public:
		MutantStack<T, U>(void) : std::stack<T, U>() {};
		MutantStack<T, U>(MutantStack<T, U> const &src) : std::stack<T, U>(src) {};
		explicit MutantStack<T, U>(U const &c) : std::stack<T,U>(c) {};
		~MutantStack<T, U>(void) {};

		MutantStack<T, U>	&operator=(MutantStack<T, U> const &src)
		{
			if (this != &src)
				this->u = src.c;
			return (*this);
		}

		typedef typename std::stack<T, U>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};

		typedef typename std::stack<T, U>::container_type::reverse_iterator riterator;
		riterator rbegin() {return this->c.rbegin();};
		riterator rend() {return this->c.rend();};
};

#endif