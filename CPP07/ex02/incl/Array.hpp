/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:39:57 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/02 17:40:52 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>



template<typename T>

class Array
{
    private:
        T *_data;
        unsigned int _size;
    public:
    	Array(void): _data(NULL), _size(0) {}
		Array(unsigned int n): _data(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = 0;
		}
        Array(Array const &src):_size(src._size)
        {
            if (src._data)
            {
                this->_data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    this->_data[i] = src._data[i];
                
            }
            else
                _data = NULL;
        }
        Array &operator=(Array const &src)
        {
            if (this != &src)
            {
                this->_size = src._size;
                if (src._data)
                {
                    if (_data)
                        delete[] _data;
                    this->_data = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        this->_data[i] = src._data[i];
                }
                else
                    this->_data = NULL;
            }
            return (*this);
        };
        ~Array()
        {
            if (this->_data)
                delete [] _data;
        };
        
        class isOutOfBounds: public std::exception
        {
            public: 
                virtual const char *what() const throw()
                {
                    return  "Wrong index";
                }
        };
        
        const T &operator[](unsigned int n)const
        {
            if ( n < 0 || n >= this->_size)
                throw isOutOfBounds();
            else
                return this->_data[n];
        };
        
        T &operator[](unsigned int n)
        {
            if ( n < 0 || n >= this->_size)
                throw isOutOfBounds();
            else
                return this->_data[n];
        };
        unsigned int size()const
        {
            return this->_size;
        };
};



#endif