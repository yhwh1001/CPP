/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:56:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/24 10:00:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 10000

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int main() {
	{
		separator("Basic tests");
		Span sp = Span(5);
		sp.addNumber(3);
		sp.addNumber(10);
		sp.addNumber(2);
		sp.addNumber(4);
		sp.addNumber(-3);

		std::cout << sp.getSize() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	
	{
		separator("10001 numbers with exception");
		Span sp = Span(MAX_VAL + 1);
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			unsigned int value = rand();
			sp.addNumber(value);
		}
		try {
			
		sp.addNumber(31);
		sp.addNumber(20);
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << sp.getSize() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	
	{
		separator("Iterator range vector");
		std::vector<int> vec;
		vec.push_back(3);
		vec.push_back(100);
		vec.push_back(52);
		vec.push_back(32);
		vec.push_back(87);
		
		try { 
		Span sp(7);
		sp.addRange(vec.begin(), vec.end());
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		separator("Iterator range exception");
		std::vector<int> vec;
		vec.push_back(3);
		vec.push_back(100);
		vec.push_back(52);
		vec.push_back(32);
		vec.push_back(87);
		
		try { 
		Span sp(3);
		sp.addRange(vec.begin(), vec.end());
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		separator("Regular array exception");
		int arr[] = {4};
		Span sp = Span(4);
		sp.addRange(arr, arr + 1);
		try {
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	
	}
	

}