/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:40:23 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/11/28 19:04:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
   private:
	int                 _fixedPointValue;
	static const int    _fractionalBits = 8;

   public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif
