/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:29:06 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/10 17:47:40 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

// kinda like this, but datatype gets substituted automatically
// int max(int a, int b)
// {
// 	return (a > b) ? a : b;
// }

template <typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

