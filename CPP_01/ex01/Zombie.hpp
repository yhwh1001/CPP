/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:46 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 04:26:50 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
			Zombie();
			
			void	newZombie(std::string newName);
			void	announce();
			~Zombie();

private:
			std::string name;

};
	Zombie*	zombieHorde(int N, std::string name);

#endif
