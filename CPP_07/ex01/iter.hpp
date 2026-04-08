/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:49:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/08 10:39:24 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* arr, const size_t len, void (*func)(T const&)) {
	for (size_t m = 0; m < len; m++) {
		func(arr[m]);
	}
};

template <typename T>
void	print(T const& m) {
	std::cout << m << std::endl;
}

#endif