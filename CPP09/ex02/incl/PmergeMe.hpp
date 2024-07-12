/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:46:46 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/12 17:39:58 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int>    _vect;
        std::vector<int>    _vInf;
        std::vector<int>    _vSup;
		int		_nbtmp;
        void    _toVector(int ac, char **av);
        void    _makePairs();
        void    _mergeSortVec(std::vector<int> &sup, std::vector<int> &inf);
        void	_printVector(std::vector<int> vec);
    public:
        PmergeMe(/* args */);
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &src);
        void    ToStartJF(int ac, char **av);
        class Error: public std::exception
        {
            public:
                virtual const char *what() const throw(){
                    return "Error";
                }
        };
        ~PmergeMe();
};



#endif