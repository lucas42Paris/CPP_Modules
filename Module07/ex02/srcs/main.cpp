/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:02:03 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:54:55 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define NB_VALUES 20
#define LESS_VALUES 5
#define MORE_VALUES 25

void	checkArrayValuesAgainstControl(Array<int> &array, int *control)
{
	bool	ok = true;

	std::cout << "[CHECK ARRAY ASSIGNMENT VALUES]" << std::endl;

	std::cout << "Control:\t";
	
	for (int i = 0; i < NB_VALUES; i++)
		std::cout << "[" << control[i] << "] ";

	std::cout << std::endl << "Array:\t\t";
	
	for (int i = 0; i < NB_VALUES; i++)
	{
		if (array[i] != control[i])
		{
			ok = false;
			std::cout << RED "[" << array[i] << "] " RESET;
		}
		else
			std::cout << GREEN "[" << array[i] << "] " RESET;
	}

	std::cout << std::endl << "--> Array value assignment checker: ";
	
	if (ok == false)
		std::cerr << RED BOLD "KO: Incorrect array values!" RESET << std::endl;
	else
		std::cout << GREEN BOLD "OK." RESET << std::endl;
	return ;
}

void	copyConstructorTest(Array<int> &array)
{
	std::cout << std::endl << YELLOW "[COPY CONSTRUCTOR TEST]" RESET << std::endl;
	
	bool	ok = true;
	std::cout << "Array (size " << array.size() << "):\t" << array << std::endl;

	Array<int>	copy(array);
	std::cout << "Copy (size ";

	if (copy.size() == array.size())
		std::cout << GREEN;
	else
		std::cout << RED;

	std::cout << copy.size() << RESET "):\t\t";

	for (int i = 0; i < NB_VALUES; i++)
	{
		if (copy[i] != array[i])
		{
			ok = false;
			std::cout << RED "[" << copy[i] << "] " RESET;
		}
		else
			std::cout << GREEN "[" << copy[i] << "] " RESET;
	}

	std::cout << std::endl << "--> Copy value checker: ";

	if (ok == false)
		 std::cout << RED BOLD "KO: Copy values do not match original array values" RESET 
		 		   << std::endl;
	else
		std::cout << GREEN BOLD "OK." RESET << std::endl;
}

void	subscriptOperatorByIndexTest(Array<int> &array, int index)
{
	bool	expectExecption = false;

	if (index >= NB_VALUES || index < 0)
		expectExecption = true;

	try
	{
		std::cout << "Array[" << index << "] = 0:\t";
		array[index] = 0;

		if (expectExecption)
			std::cout << RED BOLD "KO! " RESET RED "Did not throw exception. (Expected exception)" RESET << std::endl;
		else
			std::cout << GREEN BOLD "OK: " RESET GREEN "Did not throw exception." RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		if (expectExecption)
			std::cout << GREEN BOLD "OK. " RESET GREEN "Got exception: " << e.what()
				<< " (Expected exception)" RESET << std::endl;
		else
			std::cout << RED BOLD "KO! " RESET RED "Got exception: " << e.what()
				<< " (Should not have thrown exception)" RESET << std::endl;
	}
}

void	subscriptOperatorTest(Array<int> &array)
{
	std::cout << std::endl << YELLOW "[SUBSCRIPT [] OPERATOR TEST]" RESET << std::endl;

	std::cout << "Array: " << array << std::endl;

	::subscriptOperatorByIndexTest(array, 0);
	::subscriptOperatorByIndexTest(array, LESS_VALUES);
	::subscriptOperatorByIndexTest(array, NB_VALUES - 1);
	::subscriptOperatorByIndexTest(array, -1);
	::subscriptOperatorByIndexTest(array, NB_VALUES);
	::subscriptOperatorByIndexTest(array, MORE_VALUES);

	std::cout << "Result: " << array << std::endl;
}

void	assignmentOperatorTest(Array<int> &array)
{
	std::cout << std::endl << YELLOW "[ASSIGNMENT OPERATOR TEST]" RESET << std::endl;
	
	std::cout << CYAN "Array (size " << array.size() << "):\t\t" << array << RESET << std::endl;
	Array<int> zeroArray(LESS_VALUES);
	
	for (int i = 0; i < LESS_VALUES; i++)
		zeroArray[i] = 0;

	std::cout << "Zero Array (size " << zeroArray.size() << "):\t\t" << zeroArray << std::endl;
	array = zeroArray;
	std::cout << CYAN "Array assigned (size " << array.size() << "):\t" << array << RESET << std::endl;

	Array<int> oneArray(MORE_VALUES);
	
	for (int i = 0; i < MORE_VALUES; i++)
		oneArray[i] = 1;
		
	std::cout << "One Array (size " << oneArray.size() << "):\t\t" << oneArray << std::endl;
	array = oneArray;
	std::cout << CYAN "Array assigned (size " << array.size() << "):\t" << array << RESET << std::endl;
}

int	main(void)
{
	{
		std::cout << PURPLE "[INT TEST]" RESET << std::endl;

		Array<int>	numbers(NB_VALUES);
		int			*controlArray = new int[NB_VALUES];

		std::srand(std::time(NULL));

		for (int i = 0; i < NB_VALUES; i++)
		{
			const int	value = std::rand() % 100;
			numbers[i] = value;
			controlArray[i] = value;
		}

		::checkArrayValuesAgainstControl(numbers, controlArray);
		delete [] controlArray;

		::copyConstructorTest(numbers);
		::subscriptOperatorTest(numbers);
		::assignmentOperatorTest(numbers);
	}

	{
		std::cout << std::endl << PURPLE "[STRING TEST]" RESET << std::endl;

		Array<std::string>	strings(3);
		
		strings[0] = "Hello";
		strings[1] = "World";
		strings[2] = "!!";
		
		std::cout << CYAN "String array (size " << strings.size() 
				  << "):\t" << strings << RESET << std::endl;
		
		Array<std::string>	otherStrings(2);
		
		otherStrings[0] = "Coucou";
		otherStrings[1] = "La vie est belle.";
		
		std::cout << "Other strings (size " << otherStrings.size()
				  << "):\t" << otherStrings << std::endl;

		strings = otherStrings;

		std::cout << CYAN "String array (size " << strings.size()
				  << "):\t" << strings << RESET << std::endl;
		try
		{
			strings[3] = "Extra.";
			std::cout << RED "Accessed out of bounds index [3], "
				"but no exception thrown..." RESET << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cout << GREEN "Accessed out of bounds index [3], "
				"and got exception: " << e.what() << RESET << std::endl;
		}
	}

	return (0);
}
