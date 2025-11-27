/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:36 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/27 18:29:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream> 

int	main() {
	Harl harl;
    
    std::cout << "=== Testing all valid levels ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "[DEBUG]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "=== Testing invalid levels ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "[INVALID]" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;
    
    std::cout << "[lowercase test]" << std::endl;
    harl.complain("debug");
    std::cout << std::endl;
    
    std::cout << "[Empty string]" << std::endl;
    harl.complain("");
    std::cout << std::endl;
    
    // std::cout << "=== Random complaining ===" << std::endl;
    // std::cout << std::endl;
    
    // harl.complain("ERROR");
    // harl.complain("DEBUG");
    // harl.complain("WARNING");
    // harl.complain("INFO");
	return 0;
}
