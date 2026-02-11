/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:49:20 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/11 15:51:42 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArr[] = {3, 6, 9};
	iter(intArr, 3, print<int>);

	std::string strArr[] = {"Creation", "Order", "Rebirth","Thank", "You"};
	iter(strArr, 5, print<std::string>);
}