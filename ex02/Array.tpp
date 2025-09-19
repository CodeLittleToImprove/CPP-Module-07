/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:14:27 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/19 16:14:28 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Default constructor
template <typename T>
Array<T>::Array():
_data(NULL), _size(0)
{

}

// Parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n)
	:_data(NULL), _size(0)
{
	if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
	{
		throw std::overflow_error("Array size too large to allocate");
	}
	_data = new T[n](); // () needed to initialize default datatypes to not have trash values
	_size = n;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other)
	:_data(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

// Assignment constructor
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		this->_size = other._size;
		this->_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			this->_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
// Exceptions
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds \n");
}