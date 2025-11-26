/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:38 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 15:13:32 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA() {

// }

HumanA::HumanA(std::string n, Weapon& w): name(n), weapon(w) {
        //                            		 ↑ Initializer list
        // Members are initialized BEFORE entering this body
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
