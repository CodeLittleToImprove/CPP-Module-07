#pragma once
// #include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array():
_data(NULL), _size(0)
{

}

// Parameterized Constructor
template <typename T>
Array<T>::Array(unsigned int n)
	:_data(new T[n]), _size(n)
{

}

template <typename T>
Array<T>::Array(const Array &other)
	:_data(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

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
	return ("Index out of bounds");
}