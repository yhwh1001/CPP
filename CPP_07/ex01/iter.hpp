/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:49:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/11 15:25:26 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* arr, size_t len, void (*func)(T const&)) {
	for (size_t m = 0; m < len; m++) {
		func(arr[m]);
	}
};

template <typename T>
void	print(T const& m) {
	std::cout << m << std::endl;
}

#endif