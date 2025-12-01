/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:17:33 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/30 19:54:50 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap yuni ("Yuni");
	ClapTrap banto ("Banto");

	banto.takeDamage(387);
	yuni.attack("Roshi");
	banto.attack("Roshi");
	
	yuni = banto;
	yuni.beRepaired(9999999);
	yuni.attack("\nnothing");
	
	ClapTrap clone(yuni);
	clone.attack("Shadow");
}