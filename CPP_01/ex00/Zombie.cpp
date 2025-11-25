/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:43 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 03:56:50 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string Name) {
	name = Name;
}

void Zombie::announce() {
	std::cout << name << ": BRAaaAIiiIINNnNnnnNZZZZZZzzzzz" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is tired, needs rest \n\tXxX" << std::endl;
}
