/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:25:12 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 01:52:57 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string n): ClapTrap(n) {
	std::cout << "FragTrap " 
			  << name 
			  << " origins <BAM BAM BAAAAAM>"<< std::endl;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy) {
	std::cout << "Fragtrap clones are dangerous\n" 
			  << name 
			  << " is building itself"<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	std::cout << "\nThe original " 
			  << this->name 
			  << " FragTrap transforms itself into  " 
			  << copy.name 
			  << "\n" << std::endl;
	if(this != &copy) {
		this->name = copy.name;
		this->health = copy.health;
		this->energy = copy.energy;
		this->damage = copy.damage;	
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "\nFragtrap " 
			  << name 
			  << " is searching...\nWants some self care\nFound HIGH FIVEEES\n" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " 
			  << name 
			  << ": Enough is enough, learn to say no when yes and yes when no?" 
			  << std::endl;
}