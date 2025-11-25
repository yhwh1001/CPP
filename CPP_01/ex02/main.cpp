/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:01:16 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/25 05:26:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int	main() {
	std::string brain;
	brain = "HI THIS IS BRAIN";

	std::string& ref = brain;
	std::string* ptr = &brain;

	std::cout << "\n\t === MEMORY ADRESS ===\n" << std::endl;
	std::cout << "String adress: " << &brain << std::endl;
	std::cout << "Pointer adress: " << ptr << std::endl;
	std::cout << "Reference adress: " << &ref << std::endl;
	std::cout << "\n\t === VALUE ===" << std::endl;
	std::cout << "String value: " << brain << std::endl;
	std::cout << "Pointer value: " << *ptr << std::endl;
	std::cout << "Reference value: " << ref << std::endl;
	return 0;
}