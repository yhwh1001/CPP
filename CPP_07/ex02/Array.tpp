/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:54:24 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/11 17:52:31 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other): _arr(new T[other._size]()), _size(other._size) {
	for (unsigned int m = 0; m < other._size; m++)
		_arr[m] = other._arr[m];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _arr;
		_arr = new T[other._size]();
		_size = other._size;
		for (unsigned int m = 0; m < other._size; m++)
			_arr[m] = other._arr[m];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

template <typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= static_cast<int>(_size))
		throw std::exception();
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= static_cast<int>(_size))
		throw std::exception();
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;	
}
