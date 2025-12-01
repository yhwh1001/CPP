/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:01:13 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 02:16:45 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"  // Include both parents
#include "FragTrap.hpp"
#include <string>
#include <iostream>

// MULTIPLE INHERITANCE: DiamondTrap inherits from BOTH ScavTrap AND FragTrap
// Syntax: class Child : public Parent1, public Parent2
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		// NAME SHADOWING: DiamondTrap has its OWN name
		// This is SEPARATE from ClapTrap::name
		std::string name;

	public:
		DiamondTrap(const std::string n);  // Parameterized constructor
		DiamondTrap(const DiamondTrap& copy);  // Copy constructor
		DiamondTrap& operator=(const DiamondTrap& copy);  // Assignment operator
		~DiamondTrap();  // Destructor

		// Special method that shows BOTH names
		void	whoAmI();

		// DiamondTrap uses ScavTrap's attack (not ClapTrap's or FragTrap's)
		using ScavTrap::attack;
};

#endif