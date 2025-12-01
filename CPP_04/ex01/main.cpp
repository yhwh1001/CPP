/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:57:23 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 07:52:47 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include "Brain.hpp"

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
separator("Testing Animal types: ");
std::cout << meta->getType() << " " << std::endl;
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
separator("Is brain working?");
meta->makeSound();
dog->makeSound();
cat->makeSound();

separator("Using Copy (Cat) and Assignment (Dog) Operators");
const Cat* kitty = new Cat();
// Cat copy_kitty(kitty);
Cat copy_kitty = *kitty; // deep copy on stack
Dog copy_dog = *(static_cast<const Dog*>(dog)); //deep copy on stack
separator("Making some noise");
kitty->makeSound();
copy_kitty.makeSound();
dog->makeSound();
copy_dog.makeSound();
separator("Deep deep test");
delete kitty;
delete dog; // should not affect copy_dog and not cause memory leaks
copy_kitty.makeSound();
copy_dog.makeSound();
separator("Deleting Animals");
delete meta;
delete cat;
separator("Creating an array of Animals");
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
separator("Deleting array of Animals");
for (int i = 0; i < 4; i++) {
    delete animals[i];
}
return 0;
}
