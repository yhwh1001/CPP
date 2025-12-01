/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:02:55 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 02:39:53 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// PARAMETERIZED CONSTRUCTOR
// CRITICAL: With virtual inheritance, the MOST DERIVED class (DiamondTrap)
// must initialize the virtual base class (ClapTrap) DIRECTLY!
DiamondTrap::DiamondTrap(const std::string n)
	: ClapTrap(n + "_clap_name"),  // ClapTrap name gets "_clap_name", order matters
	  ScavTrap(n),
	  FragTrap(n),
	  name(n) {                     // DiamondTrap's own name (shadows ClapTrap::name)
	std::cout << "DiamondTrap " << this->name << " constructed with DIAMOND POWER!" << std::endl;
	// DiamondTrap has a special mix of attributes:
	this->health = FragTrap::health;   // 100 HP from FragTrap
	this->energy = ScavTrap::energy;   // 50 energy from ScavTrap
	this->damage = FragTrap::damage;   // 30 damage from FragTrap
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
	: ClapTrap(copy),
	  ScavTrap(copy),
	  FragTrap(copy),
	  name(copy.name) {    // Copy DiamondTrap name
	std::cout << "DiamondTrap Cloning " << this->name 
			  << " effortless..."<< std::endl;
}

// ASSIGNMENT OPERATOR
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap " << this->name
	          << " becomes one with " << copy.name << std::endl;

	if (this != &copy) {
		// Call parent assignment operators
		ClapTrap::operator=(copy);
		ScavTrap::operator=(copy);
		FragTrap::operator=(copy);

		// Copy DiamondTrap's own name
		this->name = copy.name;
	}
	return *this;
}

// DESTRUCTOR
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name
	          << " destroyed! The diamond breaks after all..." << std::endl;
}

// SPECIAL METHOD: whoAmI()
// This demonstrates NAME SHADOWING:
// - this->name = DiamondTrap's private name
// - ClapTrap::name = the base class name (with "_clap_name" suffix)
void DiamondTrap::whoAmI() {
	std::cout << "\n=== WHO AM I? ===" << std::endl;
	std::cout << "My DiamondTrap name is: " << this->name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::name << std::endl;
	std::cout << "================" << std::endl;
}
