/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:05:40 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/24 10:28:31 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;	
		
		iterator begin() {
			return this->c.begin();
		}
		
		iterator end() {
			return this->c.end();	
		}	
};

// template <typename T>
// typename MutantStack<T>::iterator MutantStack<T>::begin() {
// 	return this->c.begin();
// }

// template <typename T>
// typename MutantStack<T>::iterator MutantStack<T>::end() {
// 	return this->c.end();
// }

#endif

//  This is roughly how std::stack is implemented:
//   template <typename T, typename Container = std::deque<T>>
//   class stack {
//   protected:
//       Container c;  // The underlying container doing the actual work!

//   public:
//       void push(const T& value) { c.push_back(value); }
//       void pop() { c.pop_back(); }
//       T& top() { return c.back(); }
//       bool empty() const { return c.empty(); }
//       size_t size() const { return c.size(); }
//   };
