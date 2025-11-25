/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:51 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 04:58:29 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int N;
	int	M;
	
	N = 4;
	M = 6;
	std::cout << "\n\n === ZOMBIE HORDE ===\n\n ===   CREATION  ===\n" << std::endl;
	Zombie* franks = zombieHorde(N,"Frank");
	Zombie* guloso = zombieHorde(M, "Gluton");
	for (int m = 0; m < N; m++) {
	franks[m].announce();
	}
	std::cout << "\nGooood raaww brainzz are there more?\n" << std::endl;

	for (int m = 0; m < M; m++) {
	guloso[m].announce();
	}
	std::cout << "\nEnough brainzz, lose heart\n" << std::endl;
	delete[] franks;
	std::cout << "\n...\n" << std::endl;
	delete[] guloso;
}