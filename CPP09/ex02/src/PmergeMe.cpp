/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:23:42 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/12 18:15:56 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"


PmergeMe::PmergeMe(void) : _nbtmp(-1)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	if (this != &src)
		*this = src;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}


void    PmergeMe::_toVector(int ac, char **av)
{
    for (int i = 1; i < ac ; i++)
    {
        std::istringstream is(av[i]);
        int         nb;
        char        rest;
        if (is >> nb &&  !(is >> rest))
            this->_vect.push_back(nb);
        else
        {
            throw Error();
        }
    }
    for (size_t i = 0; i < _vect.size(); i++)
    {
        if (_vect[i] < 0)
            throw Error();
    }
    for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); ++it)
    {
        if (find(it + 1, _vect.end(), *it) != _vect.end())
            throw Error();
    }
}

void	PmergeMe::_printVector(std::vector<int> vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
		std::cout << ' ' << vec[i];
	std::cout << std::endl;
}


void    PmergeMe::_makePairs()
{
    if (_vect.size() % 2 != 0 )
    {
        this->_nbtmp = _vect[_vect.size() - 1];
        _vect.pop_back();
    }
    for (size_t i = 0; i < _vect.size(); i += 2)
    {
        if (_vect[i] < _vect[i + 1])
        {
            _vInf.push_back(_vect[i]);
            _vSup.push_back(_vect[i + 1]);
        }
        else
        {
            _vInf.push_back(_vect[i + 1]);
            _vSup.push_back(_vect[i]);
        }
    }
    
}

void    PmergeMe::_mergeSortVec(std::vector<int> &sup, std::vector<int> &inf)
{
    if (sup.size() > 1)
    {
        int median = sup.size() / 2;
        std::vector<int> supLeftHalf;
		supLeftHalf.assign(sup.begin(), sup.begin() + median);

		std::vector<int> supRightHalf;
		supRightHalf.assign(sup.begin() + median, sup.end());

		std::vector<int> infLeftHalf;
		infLeftHalf.assign(inf.begin(), inf.begin() + median);

		std::vector<int> infRightHalf;
		infRightHalf.assign(inf.begin() + median, inf.end());
    
        _mergeSortVec(supLeftHalf, infLeftHalf);
        // _mergeSortVec(supRightHalf, infRightHalf);

        size_t i = 0;
        size_t j = 0;
        size_t k = 0;
        while (i < supLeftHalf.size() && j < supRightHalf.size())
        {
            if (supLeftHalf[i] < supRightHalf[j])
            {
                sup[k] = supLeftHalf[i];
                inf[k] = infLeftHalf[i];
                std::cout << "i++ inf[k]-> " <<  inf[k] << std::endl;
                std::cout << "i++ sup[k]-> " <<  sup[k] << std::endl;
                i++;
            }
            else
            {
                sup[k] = supRightHalf[j];
                inf[k] = infRightHalf[j];
                std::cout << "j ++ inf[k]-> " <<  inf[k] << std::endl;
                std::cout << "j ++ sup[k]-> " <<  sup[k] << std::endl;
                j++;
            }
            k++;
        }
        while(i < supLeftHalf.size())
        {
            sup[k] = supLeftHalf[i];
            inf[k] = infLeftHalf[i];
            std::cout << "i < supLeftHalf.size() -> i ++ inf[k]-> " <<  inf[k] << std::endl;
            std::cout << "i < supLeftHalf.size() -> i ++  sup[k]-> " <<  sup[k] << std::endl;
            i++;
            k++;
        }
        while(j < supRightHalf.size())
        {
            sup[k] = supRightHalf[j];
            inf[k] = infRightHalf[j];
            j++;
            k++;
        }
    }
    _printVector(inf);
    std::cout << "| |" << std::endl;
    _printVector(sup);
    std::cout << "| |" << std::endl;
}

void PmergeMe::ToStartJF(int ac, char **av)
{
    int size = ac - 1;
	clock_t	tVec;
        // _makePairs();
	_toVector(ac, av);
    _makePairs();
    _mergeSortVec(this->_vSup, this->_vInf);
    // _makePairs();
    // _printVector(this->_vect);
    _printVector(this->_vInf);
    _printVector(this->_vSup);
	// _sortVector();
	tVec = clock();

	// clock_t tDeq;
	// _toDeque(ac, av);
	// _sortDeque();
	// tDeq = clock();

	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << ' ';
	std::cout << std::endl << "After: ";
	// _printVector(this->_vecFinal);
	// // isSortedVec(_vecFinal);
	// // isSortedDeq(_deqFinal);
	// // isSameSize(ac);
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> : " << static_cast<float>(tVec)/CLOCKS_PER_SEC << " seconds" << std::endl;	
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int> : " << static_cast<float>(tDeq)/CLOCKS_PER_SEC << " seconds" << std::endl;
}