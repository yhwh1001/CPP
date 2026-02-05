/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:21:54 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/05 17:29:17 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int		main() {
	// Create obj on stack
	separator("Stack obj");
	Data obj;
	obj.name = "STACK";
	obj.value = 9;
	
	std::cout << "String: " << obj.name << std::endl;
	std::cout << "Value: " << obj.value << std::endl;
	std::cout << "Object address: " << &obj << std::endl;
	uintptr_t raw_stack = Serializer::serialize(&obj);
	std::cout << "Serialized uInt: " << raw_stack << std::endl;
	Data* obj_deserial = Serializer::deserialize(raw_stack);
	std::cout << "Deserial String: " << obj_deserial->name << std::endl;
	std::cout << "Deserial Value: " << obj_deserial->value << std::endl;
	std::cout << "Deserial address: " << obj_deserial << std::endl;
	
	//Create object on heap
	separator("HEAP ptr");
	Data* ptr = new Data();
	ptr->name = "HEAP";
	ptr->value = 99;

	std::cout << "String: " << ptr->name << std::endl;
	std::cout << "Value: " << ptr->value << std::endl;
	std::cout << "Object address: " << ptr << std::endl;
	uintptr_t raw_heap = Serializer::serialize(ptr);
	std::cout << "Serialized uInt: " << raw_heap << std::endl;
	Data* ptr_deserial = Serializer::deserialize(raw_heap);
	std::cout << "Deserial String: " << ptr_deserial->name << std::endl;
	std::cout << "Deserial Value: " << ptr_deserial->value << std::endl;
	std::cout << "Deserial address: " << ptr_deserial << std::endl;
	
	delete ptr;
	return 0;
}