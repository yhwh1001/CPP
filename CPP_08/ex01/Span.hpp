/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:54:37 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/24 10:03:05 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span {
	private:
		std::vector<int>	_numbers;
		unsigned int		_max_size;
		
	public:
			Span();
			Span(unsigned int N);
			Span(const Span& other);
			Span& operator=(const Span& other);
			~Span();

			unsigned int	getSize() const;
			void			addNumber(int nbr);
			int				shortestSpan();
			int				longestSpan();
			
			template <typename Iterator>
			void 			addRange(Iterator begin, Iterator end);
};

// template <typename T>
// Compiler needs to figure out what T is. T is the container type, but you're passing iterator types.

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	if (end - begin > _max_size)
		throw std::logic_error("Range is too big for span");
	for (Iterator it = begin; it != end; it++) {
		int value = *it;
		addNumber(value);
	}
}

#endif
