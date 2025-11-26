/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:03 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 16:47:20 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	{
	Weapon death_star = Weapon("DEATH STAR");
	HumanA bob("B.o.B.", death_star);
	bob.attack();
	death_star.setType("KATANA");
	bob.attack();
	}
	{
		Weapon atom = Weapon("little bomb");
		HumanB jo("Jo");
		jo.attack();
		jo.setWeapon(atom);
		jo.attack();
		atom.setType("MEGA BOMB\n");
		jo.attack();
		Weapon another = Weapon("SUPER MEGA BOMB");
		jo.setWeapon(another);
		jo.attack();
	}
}
