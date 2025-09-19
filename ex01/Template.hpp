/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:59:16 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/19 16:03:39 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

//this is called function template
template <typename T>
void printElement(const T &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void increaseElement(T &elem)
{
	++elem;
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
// advantage functor can store data inside of it
struct Increment
{
	template <typename T>
	void operator()(T &x) //
	{
		++x;
	}
};
