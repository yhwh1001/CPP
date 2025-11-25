/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:49 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 04:53:19 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>


Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	for (int m = 0; m < N; m++) {
		std::stringstream ss;
		ss << name << "_" << m;
		horde[m].newZombie(ss.str());
	}
	return horde;
}
