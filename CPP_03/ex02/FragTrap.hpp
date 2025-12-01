/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:25:21 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 01:26:47 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap 
{
	public: 
		FragTrap(const std::string n);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& copy);
		~FragTrap();

	void	highFivesGuys(void);

};

#endif