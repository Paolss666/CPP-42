/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:29:13 by npaolett          #+#    #+#             */
/*   Updated: 2024/07/02 17:49:08 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/iter.hpp"

int main(void)
{
    int array[7] = {1, 2, 3, 4, 5, 6};
    std::cout << "size of array => " << ::sizeArray(array) << std::endl;
    iter(array, ::sizeArray(array), ::printFt<int>);
    

    char  arrayFo[] = {'c', 'a', 'b', 'c', 'd'};
    std::cout << "size of array => " << ::sizeArray(arrayFo) << std::endl;
    iter(arrayFo, ::sizeArray(arrayFo), ::printFt<char>);
    
    
    std::string  arrayString[6] = {"coco", "caca", "gaga", "faufau", "laolao"};
    // std::cout << "size of array => " << ::sizeArray(arrayString) << std::endl;
    iter(arrayString, 6, ::printFt<std::string>);


    double  arrayDouble[] = {0.40, 0.4777777, -3434.44};
    // std::cout << "size of array => " << ::sizeArray(arrayString) << std::endl;
    iter(arrayDouble, ::sizeArray(arrayDouble), ::printFt<double>);

    std::cout << "TEST ARRAY EMPTY"<< std::endl;
    double  arrayNULL[] = {0.0};
    std::cout << "size of array => " << ::sizeArray(arrayNULL) << std::endl;
    iter(arrayNULL, ::sizeArray(arrayNULL), ::printFt<double>);
}