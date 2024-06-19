/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:40:04 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/19 11:53:30 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"

int main(void)
{
        std::cout << std::endl << "*** SUBJECT TEST***" << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl;
		delete i;
		delete j;
		delete meta;


		std::cout  << std::endl << "*** Copying a cat and assignement to a dog ***"  << std::endl << std::endl;
		Animal *	cat = new Cat();
		Animal *	dog = new Dog();

		*dog = *cat;
		
		cat->makeSound();
		dog->makeSound();

		delete dog;
		delete cat;

		std::cout << std::endl << "*** Tests WrongAnimal ***" << std::endl;
		std::cout << std::endl;
		
		const WrongAnimal* meta2 = new WrongAnimal();
		const WrongAnimal* i2 = new WrongCat();
		const WrongCat* j2 = new WrongCat();

		std::cout << i2->getType() << " " << std::endl;

		meta2->makeSound();
		i2->makeSound();
		j2->makeSound();

		delete i2;
		delete j2;
		delete meta2;
}