/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:36 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/27 20:36:09 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

int getLevelNumber(std::string level) 
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;
    }
    return -1;  // Invalid
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return 1;
    }
    
    Harl harl;
    int lvl_nbr;
    lvl_nbr = getLevelNumber(argv[1]);
    switch (lvl_nbr) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << " STOP MESSING AROUND HAAAAAARLLL\n";
    }    
    return 0;
}

// int	main() {
// 	Harl harl;
    
//     std::cout << "=== Testing all valid levels ===" << std::endl;
//     std::cout << std::endl;
    
//     std::cout << "[DEBUG]" << std::endl;
//     harl.complain("DEBUG");
//     std::cout << std::endl;
    
//     std::cout << "[INFO]" << std::endl;
//     harl.complain("INFO");
//     std::cout << std::endl;
    
//     std::cout << "[WARNING]" << std::endl;
//     harl.complain("WARNING");
//     std::cout << std::endl;
    
//     std::cout << "[ERROR]" << std::endl;
//     harl.complain("ERROR");
//     std::cout << std::endl;
    
//     std::cout << "=== Testing invalid levels ===" << std::endl;
//     std::cout << std::endl;
    
//     std::cout << "[INVALID]" << std::endl;
//     harl.complain("INVALID");
//     std::cout << std::endl;
    
//     std::cout << "[lowercase test]" << std::endl;
//     harl.complain("debug");
//     std::cout << std::endl;
    
//     std::cout << "[Empty string]" << std::endl;
//     harl.complain("");
//     std::cout << std::endl;
    
// 	return 0;
// }
