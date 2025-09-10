#pragma once

# include <iostream>

//template <typename T>
//void print( T&input)
//{
//std::cout << input << std::endl;
//}

template <typename T>
void printElement(const T& elem)
{
	std::cout << elem << std::endl;
}

template <typename T, typename F>
void iter(const T *arr, size_t length, F func)
{
	for (size_t i = 0; i < length; i++) {
		func(arr[i]);
	}
}

