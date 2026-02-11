/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:30:04 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/10 17:30:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

class whatever {
	public:
			whatever();
			whatever(const whatever& other);
			whatever& operator=(const whatever& other);
			~whatever();
	
	private:

};

#endif
