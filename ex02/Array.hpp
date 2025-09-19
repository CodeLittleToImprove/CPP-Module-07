/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:16:44 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/18 16:33:23 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T *_data;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

// When you define a template class, the compiler needs to see both:
// The declaration and
// the implementation of all member functions
# include "Array.tpp"