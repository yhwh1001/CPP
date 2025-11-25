/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:51 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 03:41:08 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << " === STACK ZOMBIE ===\n ===   CREATION  ===" << std::endl;
	randomChump("Zoro");
	std::cout << "You have done well... " << std::endl;
	
	std::cout << " === HEAP ZOMBIE ===\n ===   CREATION  ===" << std::endl;
	Zombie* frank = newZombie("Frank");
	std::cout << "frankyyy is hAAAngryyyy..." << std::endl;
	frank->announce();
	std::cout << "niceee raaww brainzz, lose heart" << std::endl;
	delete frank;
}