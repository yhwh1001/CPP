/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:47:23 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/05 19:39:15 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include <ctime>
#include <cstdlib>

Base* generate() {
	int random = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Base: A ptr" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Base: B ptr" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Base: C ptr" << std::endl;
}

void identify(Base& p) {
	// if (dynamic_cast<A*>(&p) != NULL)
	// 	std::cout << "Base: A" << std::endl;
	// else if (dynamic_cast<B*>(&p) != NULL)
	// 	std::cout << "Base: B" << std::endl;
	// else if (dynamic_cast<C*>(&p) != NULL)
	// 	std::cout << "Base: C" << std::endl;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Base: A" << std::endl;
		return ;
	}
	catch(std::exception&){}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Base: B" << std::endl;
		return ;
	}
	catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Base: C" << std::endl;
		return ;
	}
	catch (std::exception&) {}
}

int	main() {
	srand(time(NULL));
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	return 0;
}