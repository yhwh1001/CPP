/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:06 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/26 14:52:49 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
// C++11 #include <array>
#include <deque>
#include <list>

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int main() {
	separator("Vector");
	std::vector<int> vec; // no push_front because vector stores elements in contiguous memory (like an array), time complexity would be O(n) (a lot) 
	vec.push_back(13);
	vec.push_back(23);
	vec.push_back(33);
	vec.push_back(44);
	try {
		std::vector<int>::iterator it = easyfind(vec, 323);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<int>::iterator it = easyfind(vec, 33);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	separator("Deque");
	std::deque<int> deq;
	deq.push_front(7);
	deq.push_front(27);
	deq.push_front(37);
	deq.push_front(42);
	try {
		std::deque<int>::iterator it = easyfind(deq, 323);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(deq.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator it = easyfind(deq, 37);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(deq.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	separator("List");
	std::list<int> list;
	list.push_back(5);
	list.push_back(15);
	list.push_back(35);
	list.push_front(44); //nbr in front
	try {
		std::list<int>::iterator it = easyfind(list, 323);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(list.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::list<int>::iterator it = easyfind(list, 44);	
		std::cout << "Found ocurrence " << *it << " in position " << std::distance(list.begin(), it) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
