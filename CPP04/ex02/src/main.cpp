/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:40:04 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/19 12:18:33 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"
#include "../incl/Dog.hpp"
#include "../incl/Cat.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"

#define NB_ANIMALS 4

int main(void)
{
	{
		std::cout  << "Creating one dog and one cat"  << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout  << "Creating an array of " << NB_ANIMALS << " Animals, filled half with cats, half with dogs"  << std::endl;
		Animal	*animalArray[NB_ANIMALS];
		for (int i = 0; i < NB_ANIMALS / 2; i++)
			animalArray[i] = new Cat();
		for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
			animalArray[i] = new Dog();
		for (int i = 0; i < NB_ANIMALS / 2; i++)
			animalArray[i]->makeSound();
		for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
			animalArray[i]->makeSound();
		for (int i = 0; i < NB_ANIMALS / 2; i++)
			delete animalArray[i];
		for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
			delete animalArray[i];
		
	}
	std::cout << std::endl;
	{
		std::cout  << "Creating two cats and putting ideas in each of them to verify they both have their own deep copy"  << std::endl;
		std::cout << std::endl;

		std::cout << "First cat creation" << std::endl;
		Cat	*cat = new Cat();
		cat->getBrain()->setIdeas(0, "the cat : Miaou I should take a nap...");
		cat->getBrain()->setIdeas(1, "the cat : Time for a little walk outside miaou !");
		cat->getBrain()->setIdeas(2, "the cat : Rrron rrron I'm a cat rron rron");
		std::cout << std::endl;

		std::cout << "First cat ideas :" << std::endl;
		for (int i = 0; i <= 2; i++)
			std::cout << cat->getBrain()->getIdea(i) << std::endl;

		std::cout << std::endl;
		std::cout << "Second cat creation by copy" << std::endl;
		Cat	*catCopy = new Cat(*cat);
		
		std::cout << std::endl;
		std::cout << "Second cat ideas :" << std::endl;		
		std::cout << catCopy->getBrain()->getIdea(0) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(1) << std::endl;
		std::cout << catCopy->getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;

		std::cout << "Putting new ideas into second cat" << std::endl;
		catCopy->getBrain()->setIdeas(0, "the cat copy : Miaouuuuuu");
		catCopy->getBrain()->setIdeas(1, "the cat copy : Miaou miaou");
		catCopy->getBrain()->setIdeas(2, "the cat copy : I need some food...");
		std::cout << std::endl;

		std::cout << "Second cat ideas :" << std::endl;
		for (int i = 0; i <= 2; i++)
			std::cout << catCopy->getBrain()->getIdea(i) << std::endl;
		std::cout << std::endl;

		std::cout << "Deleting first cat" << std::endl;
		delete cat;
		std::cout << "Deleting second cat" << std::endl;
		delete catCopy;

	}

	std::cout << std::endl << "*** testing deep copy with copy assignement ***" << std::endl;
	Dog basic;
	basic.getBrain()->setIdeas(0, "Bou Bou");
	std::cout << "basicDog -> " << basic.getBrain()->getIdea(0) << std::endl;
	{
		Dog tmp = basic;
		std::cout << "tmpDog -> " <<  tmp.getBrain()->getIdea(0) << std::endl;

	}

	std::cout << std::endl << "*** testing deep copy with copy constructor ***" << std::endl;
	Dog dog;
	dog.getBrain()->setIdeas(0, "Bou Bou");	

	std::cout << "Dog -> " << dog.getBrain()->getIdea(0) << std::endl;
	{
		Dog copyDog = Dog(dog);
		std::cout << "cpyDog -> " << copyDog.getBrain()->getIdea(0) << std::endl;

	}
	return 0;
}