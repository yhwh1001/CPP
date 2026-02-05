/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:37:06 by mcarvalh           #+#    #+#             */
/*   Updated: 2026/02/05 14:37:06 by mcarvalh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	std::string name;
	int			value;
};

class Serializer {
	public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);

	private:
			Serializer();
			Serializer(const Serializer& other);
			Serializer& operator=(const Serializer& other);
			~Serializer();
};

#endif
