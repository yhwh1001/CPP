/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:53:28 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/11 17:48:58 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
			T*				_arr;
			unsigned int	_size;
			
	public:
			Array();
			Array(unsigned int n);
			Array(const Array& other);
			Array& operator=(const Array& other);
			~Array();

			T& operator[](int index);
			const T& operator[](int index) const;
			unsigned int size() const;
};

#include "Array.tpp"

#endif