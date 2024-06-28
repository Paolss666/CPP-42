/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:25 by npaolett          #+#    #+#             */
/*   Updated: 2024/06/28 15:56:12 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"

Base::~Base(void)
{
    std::cout << "Destructor Base called" << std::endl;
    return ;
}

Base *generate(void)
{
    Base *b;
     // Initialisation du générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int nb = (rand() % 3);
    switch (nb)
    {
        case 0:
            b = new C();
            break;
        case 1:
            b = new B();
            break;
        default:
            b = new A();
            break;
    }
    return (b);
}

void    identify(Base   *p)
{
    if (!p){
        std::cerr << "p is NULL" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    return ;
}

void    identify(Base &p)
{
    try{
        A &a = dynamic_cast<A&>(p);
        std::cout << "Class A" << std::endl;
    }
    catch(std::exception const &a)
    {
        std::cerr << a.what() << std::endl;
    }
    try{
        B &b = dynamic_cast<B&>(p);
        std::cout << "Class B" << std::endl;
    }
    catch(std::exception const &a)
    {
        std::cerr << a.what() << std::endl;
    }
    try{
        C &c = dynamic_cast<C&>(p);
        std::cout << "Class C" << std::endl;
    }
    catch(std::exception const &a)
    {
        std::cerr << a.what() << std::endl;
    }
    return ;
}