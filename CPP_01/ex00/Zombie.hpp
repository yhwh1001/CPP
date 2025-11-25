/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:36:46 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 03:34:30 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
			// Zombie();
			Zombie(std::string Name);

			void	announce();
			~Zombie();

private:
			std::string name;

};

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

#endif
