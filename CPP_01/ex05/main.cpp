/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:36 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/27 20:27:23 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream> 

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.complain(argv[1]);
    
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
