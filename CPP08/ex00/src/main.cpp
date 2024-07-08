/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:05:27 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/06 15:54:37 by npoalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"
#include <iomanip>

void    printTest(int n)
{
    std::cout << n << std::endl;
}

int main() {
    
    std::list<int> mylist;
    
    mylist.push_back(1);
    mylist.push_back(0);
    mylist.push_front(42);
    mylist.push_back(3);

    std::for_each(mylist.begin(), mylist.end(), printTest);
    
    try {
        std::list<int>::const_iterator it = ::easyfind(mylist, 3);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::list<int>::const_iterator it = easyfind(mylist, 6);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}