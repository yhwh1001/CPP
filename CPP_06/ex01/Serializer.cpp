/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:37:06 by mcarvalh           #+#    #+#             */
/*   Updated: 2026/02/05 14:37:06 by mcarvalh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other){
		//copy attributes
	}
	return *this;
}

Serializer::~Serializer() {}


