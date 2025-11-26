/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:25 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 16:38:44 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Weapon::Weapon() {
// }

Weapon::~Weapon() { 
	std::cout << type << " ist kaputt ... when is it enough?\n" << std::endl;
}

Weapon::Weapon(std::string w) {
	type = w;
	std::cout << "Building MASTER WEAPON: " << type << std::endl;

}

const std::string&	Weapon::getType() const {
	return type;
}

void	Weapon::setType(std::string newtp) {
	type = newtp;
}