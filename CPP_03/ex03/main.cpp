/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:17:33 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 02:32:48 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "=== Testing DiamondTrap ===" << std::endl;

	// Create a DiamondTrap
	DiamondTrap diamond("Sparky");

	std::cout << "\n--- Testing different attributes from classes ---" << std::endl;
	diamond.attack("Enemy");
	diamond.takeDamage(30);
	diamond.beRepaired(20);

	diamond.whoAmI();

	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	DiamondTrap clone(diamond);
	clone.whoAmI();

	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	DiamondTrap blood("Blood");
	blood = diamond;
	blood.whoAmI();

	std::cout << "\n--- Testing inherited special abilities ---" << std::endl;
	diamond.guardGate();  // From ScavTrap

	std::cout << "\n=== Destructors will be called now ===" << std::endl;
	return 0;
}