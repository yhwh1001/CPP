/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:53 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 16:46:51 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) {
	name = n;
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon& w) {
	weapon = &w;
}

void	HumanB::attack() {
	if (weapon == NULL)
		std::cout << name << " is looking for their weapon\n" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
