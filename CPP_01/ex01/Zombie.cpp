/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:43 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 04:56:49 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "\nZombie awakening..." << std::endl;
}

void	Zombie::newZombie(std::string newName) {
	name = newName;
}

void	Zombie::announce() {
	std::cout << name << ": BRAaaAIiiIINNnNnnnNZZZZZZzzzzz" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is tired, needs rest" << std::endl;
}
