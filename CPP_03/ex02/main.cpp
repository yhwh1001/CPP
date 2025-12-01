/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:17:33 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 01:45:13 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main() 
{
	ScavTrap owl("The Owl");
    ScavTrap angel("Guardian Angel");
    
    angel.attack("Enemy");
    angel.takeDamage(30);
    angel.beRepaired(222);
	
	ScavTrap ScavClone(angel);
    ScavClone.guardGate();
    
    FragTrap bomb("The Bomb");
    bomb.attack("Accounting");
    FragTrap FragClone (bomb);
    FragClone.highFivesGuys();
    FragTrap roronoa("Roronoa");
    roronoa = bomb;
    return 0;
}