/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:30 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

void toUpperCaseChar(char &c)
{
	c = static_cast<char>(toupper(c));
	// std::cout << c << std::endl;
}

void toUpperCaseString(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<char>(toupper(str[i]));
	// std::cout << str << std::endl;
}

int main()
{
	char characters[5] = {'a', 'b', 'c', 'd', 'e'};
	int numbers[5] = {1, 2, 3, 4, 5};
	const int const_numbers[3] = {10, 20, 30};
	std::string str[] = {"cats", "are", "the", "cutest"};

	std::cout << "\033[1;35m===[Capitalize char array]===\033[0m" << std::endl;
	std::cout << "original:\t";
	for (char c : characters) std::cout << c << " ";
	std::cout << std::endl;
	iter(characters, 5, toUpperCaseChar);
	std::cout << "iter result:\t";
	for (char c : characters) std::cout << c << " ";
	std::cout << std::endl;
	// iterB(characters, 5, toUpperCaseChar);

	std::cout << std::endl << "\033[1;35m===[Capitalize std::string array]===\033[0m" << std::endl;
	std::cout << "original:\t";
	for (std::string &s : str) std::cout << s << " ";
	std::cout << std::endl;
	iter(str, 4, toUpperCaseString);
	std::cout << "iter result:\t";
	for (std::string &s : str) std::cout << s << " ";
	std::cout << std::endl;
	// iterB(str, 4, toUpperCaseString);

	std::cout << "\n\033[1;35m===[Print Int array]===\033[0m" << std::endl;
	iter(numbers, 5, printElement<int>);

	std::cout << "\n\033[1;35m===[Print Const Int array]===\033[0m" << std::endl;
	iter(const_numbers, 3, printElement<int>); // prints const array


	std::cout << "\n\033[1;35m===[Increase Element in int array]===\033[0m" << std::endl;
	std::cout << "original:\t";
	for (int i : numbers) std::cout << i << " ";
	iter(numbers, 5, increaseElement<int>);
	std::cout << std::endl << "iter result:\t";
	for (int i : numbers) std::cout << i << " ";

	std::cout << std::endl << std::endl <<"\033[1;35m===[Increase numbers using a functor (Version A advantage)]===\033[0m" << std::endl;
	// advantage of version A
	std::cout << "original:\t";
	for (int i : numbers) std::cout << i << " ";
	Increment incFunction;
	iter(numbers, 5, incFunction);
	std::cout << std::endl << "iter result:\t";
	for (int i : numbers) std::cout << i << " ";
	// iterB(numbers, 5, inc); // can't use an object as function

	std::cout << std::endl << "\033[1;35m===[Increase characters using instantiated template]===\033[0m" << std::endl;
	std::cout << "original:\t";
	for (char c : characters) std::cout << c << " ";
	std::cout << std::endl;
	iter(characters, 5, increaseElement<char>); // increases prints const array
	std::cout << "iter result:\t";
	for (char c : characters) std::cout << c << " ";
	std::cout << std::endl;

	return 0;
}