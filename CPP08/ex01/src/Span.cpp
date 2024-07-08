/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:11:57 by npoalett          #+#    #+#             */
/*   Updated: 2024/07/06 15:41:38 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

Span::Span(void)
{
    return ;
}

Span::Span(unsigned int n): N(n)
{
    return ;
}

Span::Span(Span const &src)
{
    if (this != &src)
        this->N = src.N;
}

Span::~Span(void)
{
    return ;
}

Span &Span::operator=(Span const &src)
{
    if(this != &src)
        this->N = src.N;
    return (*this);
}

void   Span::addNumber(int nb)
{
    if (this->array.size() >= this->N)
        throw Span::fullArray();
    else
        this->array.push_back(nb);
    return ;
}

void   Span::addNumberSpan(std::vector<int> toAdd)
{
    std::vector<int>::iterator start = toAdd.begin();
    std::vector<int>::iterator end = toAdd.end();

    if (this->array.size() == N)
        throw Span::fullArray();
    else if ((this->array.size() + toAdd.size()) > N)
    {
        int spaceAvaiable = N - this->array.size();
        this->array.insert(this->array.end(), start, start + spaceAvaiable);
    }
    else
        this->array.insert(this->array.end(), start, end);
    return ;
}

int Span::shortestSpan(void)
{
    if (array.empty())
        throw Span::emptyArray();
    else if (array.size() > 1)
    {
        std::sort(array.begin(), array.end());
        int minDistance = array[1] - array[0];
        for (unsigned int i = 0; i < (array.size() - 1); i++)
        {
            if (array[i + 1] - array[i] < minDistance)
                minDistance = array[i + 1] - array[i];
        }
        return (minDistance); 
    }
    else
        throw Span::noDistanceFound();
}


int	Span::longestSpan(void)
{
    if (array.empty())
        throw Span::emptyArray();
	else if (array.size() > 1)
	{
		std::sort(array.begin(), array.end());
		int distMax = array[array.size() - 1] - array[0];
		return (distMax);
	}
    else 
	    throw Span::noDistanceFound();
}

void	Span::printSpan(void)
{
	std::cout << "Span : ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

const char *Span::fullArray::what(void) const throw()
{
    return ("No more space. Can't add any more numbers!!");
}

const char *Span::noDistanceFound::what() const throw()
{
    return ("No distance find: there's only one number or none");
}

const char *Span::emptyArray::what() const throw()
{
    return ("Array is empty!!");
}

