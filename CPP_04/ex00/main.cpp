/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:57:23 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 05:40:29 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << title << std::endl;
}

int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
separator("Testing Animal attributes: ");
std::cout << meta->getType() << " " << std::endl;
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
meta->makeSound();
dog->makeSound();
cat->makeSound();

separator("Testing WrongAnimal attributes: ");
const WrongAnimal* wrongAnim = new WrongAnimal();
const WrongAnimal* wrong = new WrongCat();
separator("Testing WrongAnimal attributes: ");
std::cout << wrongAnim->getType() << " " << std::endl;
std::cout << wrong->getType() << " " << std::endl;
wrongAnim->makeSound();
wrong->makeSound(); // BUG calls WrongAnimal::makeSound()
separator("Getting correct WrongCat sound");
WrongCat newer;
std::cout << "New WrongCat sound : ";
newer.makeSound();


separator("Creating an array of Animals: ");
const Animal* animals[4] = {
    new Dog(),
    new Cat(),
    new Dog(),
    new Cat()
};
for (int i = 0; i < 4; i++) {
    std::cout << "Animal " << i << " -> " << animals[i]->getType() << " : ";
    animals[i]->makeSound();
}
separator("\nDeleting Animals: ");
delete meta;
delete dog;
delete cat;
separator("Deleting Wrong Animals: ");
delete wrongAnim;
delete wrong;
separator("Deleting array of Animals: ");
for (int i = 0; i < 4; i++) {
    delete animals[i];
}

separator("STACK vs HEAP - Different Allocation");
{
    std::cout << "Stack allocation:" << std::endl;
    Dog stackDog;
    Cat stackCat;
    Animal stackAnimal;
    
    stackDog.makeSound();
    stackCat.makeSound();
    stackAnimal.makeSound();
    // Auto-destroyed when going out of scope
}

return 0;
}