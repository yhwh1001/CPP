/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:48:26 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 01:21:27 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap() {
	std::cout << "\nScavTrap " + name + ": thank you and good byeeee" << std::endl;
}

ScavTrap::ScavTrap(const std::string n): ClapTrap(n)
{
	// ClapTrap(n) already initialized: name, health=10, energy=10, damage=0
	// Now we override the stats for ScavTrap:
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "New discoveryyy welcome: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy) {
	std::cout << "\n<ANOOTHHEEER OOOONNNNEEE>\nScavtrap upgrade brudi into " << this->name << std::endl;
	// ClapTrap(copy) already copied all members - no manual copying needed!
}
		
ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "\nScavtrapping " << this->name << " majestically into " << copy.name << std::endl;
	if(this != &copy) {
		this->name = copy.name;
		this->health = copy.health;
		this->energy = copy.energy;
		this->damage = copy.damage;	
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energy > 0)
	{
		std::cout << this->name << " GROOOOWWWLLLSSSS and charges head on " << target 
				  << " with so much craziness and " << this->damage 
				  << "p of will power." << std::endl;
		this->energy--;	
	}
	else
		std::cout << "ScavTrap " << this->name
				  << "has fought well, needs more energyyyy" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is meditating...\n GATE KEEPER MODE" << std::endl;
}
