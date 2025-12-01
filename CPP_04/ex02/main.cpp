/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:57:23 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 08:08:26 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

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
separator("Abstract Animal test - cannot instantiate");
// const AAnimal* abstract_animal = new AAnimal(); // This line would cause a compilation error
AAnimal* abstract_dog = new Dog();
abstract_dog->makeSound();
separator("Deleting Animals");
delete meta;
delete cat;
delete dog;
delete abstract_dog;
return 0;
}
