/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:56:09 by npoalett          #+#    #+#             */
/*   Updated: 2024/06/19 17:36:18 by npaolett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MateriaSource.hpp"
#include "../incl/Character.hpp"
#include "../incl/Ice.hpp"
#include "../incl/Cure.hpp"


int main(void)
{
    {
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}

	{	
		std::cout << "USE DIPLAY INVENTORY" <<std::endl << std::endl;
		IMateriaSource *mat = new MateriaSource();
		mat->learnMateria(new Ice());
		mat->learnMateria(new Cure());
		
		Character *philo = new Character("philo");
		
		ICharacter *pr = new Character("gaulois");
		AMateria	*m;

		philo->displayInventory();
		// philo->use(-1, *pr);
		for (int i = 0; i <= 1; i++)
		{	
			m = mat->createMateria("ice");
			philo->equip(m);
			m = mat->createMateria("cure");
			philo->equip(m);
		}
			philo->displayInventory();
			
		for (int i = 0; i <= 3; i++)
			philo->use(i, *pr);
		delete mat;
		delete philo;
		delete pr;
	}
	{
		std::cout << std::endl << std::endl << "*** Testing Character ***" << std::endl << std::endl;		
		std::cout  << " -- Characters creation --" << std::endl;
		Character * Lollo = new Character("Lollo");
		Character * Jackie = new Character("Jackie");
		std::cout  << " -- Creating 4 Materia for the Character to equip --" << std::endl;
		IMateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		src1->learnMateria(new Cure());
		AMateria * tmp1 = src1->createMateria("ice");
		Lollo->equip(tmp1);
		AMateria * tmp2 = src1->createMateria("cure");
		Lollo->equip(tmp2);
		AMateria * tmp3 = src1->createMateria("ice");
		Lollo->equip(tmp3);
		AMateria * tmp4 = src1->createMateria("cure");
		Lollo->equip(tmp4);
		std::cout  << " -- Creating a 5th Materia for the Character to equip -> Full inventory --" << std::endl;
		AMateria * tmp5 = src1->createMateria("ice");
		Lollo->equip(tmp5);
		std::cout  << " -- Display Inventory -- " << std::endl;
		Lollo->displayInventory();
		std::cout  << " -- Fully unequip the Character --" << std::endl;
		for (int i = 0; i < 4; i++)
			Lollo->unequip(i);
		std::cout  << " -- Unequip the Character with a index already empty --" << std::endl;
		Lollo->unequip(0);
		std::cout  << " -- Unequip the Character with a wrong index --" << std::endl;
		Lollo->unequip(6);
		Lollo->unequip(-1);
		std::cout  << " -- Display Inventory -- " << std::endl;
		Lollo->displayInventory();
		std::cout  << " -- Equip of 2 Materia in the Character inventory -- " << std::endl;
		Lollo->equip(tmp1);
		Lollo->equip(tmp2);

		std::cout  << " -- Check use function -- " << std::endl;
		Lollo->use(0, *Jackie);
		std::cout  << " -- Check use on empty inventory -- " << std::endl;
		Lollo->use(2, *Jackie);
		std::cout  << " -- Check use with wrong index -- " << std::endl;
		Lollo->use(7, *Jackie);
		Lollo->use(-1, *Jackie);

		delete Lollo;
		delete src1;
		delete Jackie;
		delete tmp4;
		delete tmp3;
		
		std::cout << std::endl  << "*** ADD 2 times the same materia ***" << std::endl << std::endl;
		IMateriaSource *matS = new MateriaSource();
		matS->learnMateria(new Ice());
		matS->learnMateria(new Cure());
		
		Character *Mark = new Character("Warrior");
		ICharacter *ptr = new Character("gaolo");
		AMateria	*mater;
 
		for (int i = 0; i <= 1; i++)
		{	
			mater = matS->createMateria("ice");
			Mark->equip(mater);
			Mark->equip(mater);
		}
		AMateria *mater1= matS->createMateria("Cure");
		Mark->equip(mater1);
		Mark->equip(mater1);
		Mark->equip(mater1);
		
		Mark->displayInventory();
		Mark->use(2, *ptr);
		Mark->use(1, *ptr);
		
		mater = matS->createMateria("cure");
		// Mark->use(0, *ptr);
		Mark->displayInventory();
	
		delete mater;
		delete matS;
		delete ptr;
		delete Mark;
// 
	std::cout << std::endl << std::endl << "*** Testing deep copy ***" <<  std::endl << std::endl;
	Character basic("Momo");

	IMateriaSource * src = new MateriaSource();

	AMateria * icy1 = new Ice();

	src->learnMateria(icy1);

	AMateria * tmppp = src->createMateria("ice");
	basic.equip(tmppp);
	basic.displayInventory();
	{
		Character tmp = basic;
		tmp.displayInventory();	
	}
	basic.displayInventory();
	delete src;
	}
}