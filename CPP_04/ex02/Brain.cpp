/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 04:40:04 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 05:51:46 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (i == 77)
			ideas[i] = "eat cuddle sleep repeat";
		else if (i == 42)
			ideas[i] = "quantum space time travel";
		else
			ideas[i] = " < Empty Idea > ";
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea(int index, const std::string &thoughts) {
	if (index >= 0 && index < 100) {
		ideas[index] = thoughts;
	}
}

std::string	Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "";
}

