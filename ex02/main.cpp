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

#include "Array.hpp"

struct Color
{
	enum Code
	{
		RESET   = 0,
		RED     = 31,
		GREEN   = 32,
		YELLOW  = 33,
		BLUE    = 34,
		MAGENTA = 35,
		CYAN    = 36,
		WHITE   = 37,
		// Bright (bold) versions
		BRIGHT_MAGENTA = 95,
	};
};

void printColor(const std::string &msg, Color::Code color)
{
	std::cout << "\033[" << color << "m"
		<< msg
		<< "\033[0m";
}

// Struct for test "Complex Array Type from own struct"
struct s_test {
	int a;
	char b;
};

template <typename T>
void printOwnArray(const Array<T>& arr)
{
	if (arr.size() == 0)
	{
		std::cout << "empty array from own print function" << std::endl;
		return;
	}

	for (unsigned int i = 0; i < arr.size(); i++)
		// std::cout << arr[i] << " ";
			std::cout << "'" << arr[i] << "' | ";
	std::cout << std::endl;
}

// Test 1: Empty array creation
void test_empty_array_creation()
{
	printColor("Empty Array via default constructor \n", Color::YELLOW);
	Array<int> emptyArray1;
	printOwnArray(emptyArray1);
	printColor("size() from empty array1: ", Color::BLUE);
	std::cout << emptyArray1.size() << std::endl;
}

// Test 2: Assignment operator with empty array
void test_empty_array_assignment()
{
	printColor("\nEmpty Array via assignment constructor \n", Color::YELLOW);
	Array<int> emptyArray1;
	Array<int> emptyArray2;
	emptyArray2 = emptyArray1;
	printOwnArray(emptyArray2);
	printColor("size() from empty array2: ", Color::BLUE);
	std::cout << emptyArray2.size() << std::endl;
}

// Test 3: Copy constructor with empty array
void test_empty_array_copy()
{
	printColor("\nEmpty Array via copy constructor \n", Color::YELLOW);
	Array<int> emptyArray1;
	Array<int> emptyArray3(emptyArray1);
	printOwnArray(emptyArray3);
	printColor("size() from empty array3: ", Color::BLUE);
	std::cout << emptyArray3.size() << std::endl;
}

// Test 4: Invalid index access
void test_invalid_index_access()
{
	try
	{
		Array<int> emptyArray4;
		printColor("try access emptyArray4[0]: ", Color::BLUE);
		std::cout << emptyArray4[0];
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}
}
void test_int_arg()
{
	Array<int> intArray1(5);
	printColor("Create int array with size 5 \n", Color::YELLOW);
	printColor("intArray1.size: ", Color::BLUE);
	std::cout << intArray1.size() << std::endl;
	printColor("set numbers with [] operator: ", Color::BLUE);
	for (unsigned int i = 0; i < intArray1.size(); i++)
			intArray1[i] = i;
	printOwnArray(intArray1);
	printColor("try access intArray1[4]: ", Color::BLUE);
	std::cout << intArray1[4] << std::endl;
	try
	{
		printColor("try access intArray1[5]: ", Color::BLUE);
		std::cout << intArray1[5];
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}
	printColor("Copy array via copy constructor(deep copy test) \n", Color::YELLOW);
	Array<int> intArray2(intArray1);
	printColor("Modify intArray2[3] = 8 \n", Color::BLUE);
	intArray2[3] = 8;
	printColor("Print whole intArray1: ", Color::BLUE);
	printOwnArray(intArray1);
	printColor("Print whole intArray2: ", Color::BLUE);
	printOwnArray(intArray2);
	printColor("\nCopy array via assignment constructor(deep copy test) \n", Color::YELLOW);
	Array<int> intArray3;
	intArray3 = intArray1;
	printColor("Modify intArray3[4] = 9 \n", Color::BLUE);
	intArray3[4] = 9;
	printColor("Print whole intArray1: ", Color::BLUE);
	printOwnArray(intArray1);
	printColor("Print whole intArray3: ", Color::BLUE);
	printOwnArray(intArray3);
}

void test_double_arg()
{
	Array<double> doubleArray1(5);
	printColor("Create double array with size 5 \n", Color::YELLOW);

	printColor("doubleArray1.size: ", Color::BLUE);
	std::cout << doubleArray1.size() << std::endl;

	printColor("set numbers with [] operator: ", Color::BLUE);
	for (unsigned int i = 0; i < doubleArray1.size(); i++)
		doubleArray1[i] = i * 1.1; // example double values

	printOwnArray(doubleArray1);

	printColor("try access doubleArray1[4]: ", Color::BLUE);
	std::cout << doubleArray1[4] << std::endl;

	try
	{
		printColor("try access doubleArray1[5]: ", Color::BLUE);
		std::cout << doubleArray1[5];
	}
	catch (const Array<double>::OutOfBoundsException &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}

	printColor("Copy array via copy constructor (deep copy test) \n", Color::YELLOW);
	Array<double> doubleArray2(doubleArray1);

	printColor("Modify doubleArray2[3] = 8.8 \n", Color::BLUE);
	doubleArray2[3] = 8.8;

	printColor("Print whole doubleArray1: ", Color::BLUE);
	printOwnArray(doubleArray1);
	printColor("Print whole doubleArray2: ", Color::BLUE);
	printOwnArray(doubleArray2);

	printColor("\nCopy array via assignment operator (deep copy test) \n", Color::YELLOW);
	Array<double> doubleArray3;
	doubleArray3 = doubleArray1;

	printColor("Modify doubleArray3[4] = 9.9 \n", Color::BLUE);
	doubleArray3[4] = 9.9;

	printColor("Print whole doubleArray1: ", Color::BLUE);
	printOwnArray(doubleArray1);
	printColor("Print whole doubleArray3: ", Color::BLUE);
	printOwnArray(doubleArray3);
}

void test_string_arg()
{
	Array<std::string> strArray1(5);
	printColor("Create string array with size 5 \n", Color::YELLOW);

	printColor("strArray1.size: ", Color::BLUE);
	std::cout << strArray1.size() << std::endl;

	printColor("set strings with [] operator: ", Color::BLUE);
	strArray1[0] = "apple";
	strArray1[1] = "banana";
	strArray1[2] = "cherry";
	strArray1[3] = "date";
	strArray1[4] = "elderberry";

	printOwnArray(strArray1);

	printColor("try access strArray1[4]: ", Color::BLUE);
	std::cout << strArray1[4] << std::endl;

	try
	{
		printColor("try access strArray1[5]: ", Color::BLUE);
		std::cout << strArray1[5];
	}
	catch (const Array<std::string>::OutOfBoundsException &e)
	{
		printColor(e.what(), Color::RED);
		std::cout << std::endl;
	}

	printColor("Copy array via copy constructor (deep copy test) \n", Color::YELLOW);
	Array<std::string> strArray2(strArray1);
	printColor("Modify strArray2[2] = 'kiwi'\n", Color::BLUE);
	strArray2[2] = "kiwi";

	printColor("Print whole strArray1: ", Color::BLUE);
	printOwnArray(strArray1);
	printColor("Print whole strArray2: ", Color::BLUE);
	printOwnArray(strArray2);

	printColor("\nCopy array via assignment operator (deep copy test) \n", Color::YELLOW);
	Array<std::string> strArray3;
	strArray3 = strArray1;
	printColor("Modify strArray3[4] = 'fig'\n", Color::BLUE);
	strArray3[4] = "fig";

	printColor("Print whole strArray1: ", Color::BLUE);
	printOwnArray(strArray1);
	printColor("Print whole strArray3: ", Color::BLUE);
	printOwnArray(strArray3);
}



int main(int, char**)
{
	printColor("===[Empty Array tests]===\n", Color::BRIGHT_MAGENTA);
	test_empty_array_creation();
	test_empty_array_assignment();
	test_empty_array_copy();
	test_invalid_index_access();

	printColor("\n===[Int Array tests]===\n", Color::BRIGHT_MAGENTA);
	test_int_arg();

	printColor("\n===[Double Array tests]===\n", Color::BRIGHT_MAGENTA);
	test_double_arg();

	printColor("\n===[String Array tests]===\n", Color::BRIGHT_MAGENTA);
	test_string_arg();

	return (0);
}
