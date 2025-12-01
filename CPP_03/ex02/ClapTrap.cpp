/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:17:48 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 01:49:09 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "\n --- pLOb Blipo --- \n" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " + name + ": Beebib boop see you all in hell\n" << std::endl;
}

ClapTrap::ClapTrap(const std::string n): name(n), health(10), energy(10), damage(0) {
	std::cout << "Wakey wakeyy, time to fight for us " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy): 
name(copy.name), health(copy.health), 
energy(copy.energy), damage(copy.damage) {
	std::cout << "\n<Another ClapTrap is discovering light>\nWWelcome reborn "
	<< this->name << std::endl;
}
		
ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "\nClapping and " << this->name << " is building itself into " << copy.name << std::endl;
	if(this != &copy) {
		this->name = copy.name;
		this->health = copy.health;
		this->energy = copy.energy;
		this->damage = copy.damage;	
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energy > 0)
	{
		std::cout << this->name << " attacks " << target << " ferousciously with " << this->damage << " attack power." << std::endl;
		this->energy--;	
	}
	else
		std::cout << "ClapTrap " << this->name
				  << "is completely drained, no energyyy" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy > 0)
	{
		std::cout << "\nSUUPPERR BOOOOOSST\n Claptrap " << this->name << " : Thank you LOOORDD revitalizing " << amount << " of light" << std::endl;
		this->energy--;
	}
	else
		std::cout << "ClapTrap " << this->name
				  << "is completely drained, no energyyy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << ": this hurts " << amount << "xp but not as much as the fear of love..." << std::endl;
}
