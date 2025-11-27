/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:19:10 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/27 18:30:16 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*

Exercise to use with help of struct, cleaner but more complex:

struct LevelMap {
    std::string name;
    void (Harl::*function)(void);
};

void Harl::complain(std::string level) {
    LevelMap levels[4] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };
    
    for (int i = 0; i < 4; i++) {
        if (levels[i].name == level) {
            (this->*levels[i].function)();
            return;
        }
    }
}
*/

void	Harl::debug() {
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle"
				<< "-special-ketchup burger. I really do" << std::endl;
}

void	Harl::info() {
	std::cout	<< "I cannot believe adding extra bacon costs more money. You didn’t put"
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
				<< "years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functionsPtr[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	for (int m = 0; m < 4; m++)
	{
		if (levels[m] == level) {
		(this->*functionsPtr[m])();
			return ;
		}
	}
	std::cout << "no level reached, plob blib...\n";
}