/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:09:51 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/24 16:43:10 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


void    TestBurocrat(std::string name, int grade)
{
    try
    {
        Bureaucrat buro(name, grade);
        std::cout << buro << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
}

int main(void){
    
    TestBurocrat("lolo", 60);
        
    return 0;
}