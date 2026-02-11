/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:30:04 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/10 17:30:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

whatever::whatever() {}

whatever::whatever(const whatever& other) {
	*this = other;
}

whatever& whatever::operator=(const whatever& other) {
	if (this != &other){
		//copy attributes
	}
	return *this;
}

whatever::~whatever() {}

