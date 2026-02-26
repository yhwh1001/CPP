/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:54:37 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/26 14:54:37 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other){
		//copy attributes
	}
	return *this;
}

Span::~Span() {}

