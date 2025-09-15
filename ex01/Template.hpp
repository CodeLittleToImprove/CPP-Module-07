#pragma once

# include <iostream>

//this is called function template
template <typename T>
void printElement(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void increaseElement(T &elem)
{
	++elem;
	// std::cout << elem << std::endl;
}

// Version A – fully generic callable
template <typename T, typename F>
void iter(T *arr, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(arr[i]);
	}
}

// Version B – restricted to function pointers
template <typename T>
void iterB(T *arr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		f(arr[i]);
	}
}

// Example demonstrating why Version A is more flexible: it can accept functor objects
struct Increment
{
	template <typename T>
	void operator()(T &x)
	{
		++x;
	}
};
