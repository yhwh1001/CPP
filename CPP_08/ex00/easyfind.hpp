/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:50:46 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/03/19 15:59:21 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int m) {
	typename T::iterator it = std::find(container.begin(), container.end(), m);
	if (it == container.end())
		throw std::runtime_error("No ocurrence found");
	return it;
};




#endif
