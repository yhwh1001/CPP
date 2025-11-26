/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:54:16 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 15:28:04 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	public:
				// Weapon();
				Weapon(std::string w);
				~Weapon();

			void	setType(std::string newtp);
			const std::string&	getType() const;

	private:
				std::string type;
};

#endif
