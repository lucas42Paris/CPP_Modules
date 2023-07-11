/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:55:21 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:59:29 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C>
void	printMutantStackSize(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << name << " is empty: " << std::boolalpha << mutantStack.empty()
		<< " (size = " << mutantStack.size() << ")." << std::endl;
}

template <typename T, typename C>
void	printMutantStackTop(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << name << " top: ";
	
	if (!mutantStack.empty())
		std::cout << "[" << mutantStack.top() << "]";
	else
		std::cout << "Nothing (empty stack)";
		
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithIterator(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << CYAN "Iterator: " RESET << name << " contents begin to end: ";
	
	typename MutantStack<T, C>::iterator it = mutantStack.begin();
	typename MutantStack<T, C>::iterator ite = mutantStack.end();
	
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl << CYAN "Iterator: " RESET << name << " contents end to begin: ";
	
	it = mutantStack.begin();
	ite--;
	
	for (; ite != it; --ite)
		std::cout << "[" << *ite << "] ";
		
	std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithConstIterator(std::string name, MutantStack<T, C> const mutantStack)
{
	std::cout << YELLOW "Const iterator: " RESET << name << " contents begin to end: ";
	
	typename MutantStack<T, C>::const_iterator it = mutantStack.begin();
	typename MutantStack<T, C>::const_iterator ite = mutantStack.end();
	
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl << YELLOW "Const iterator: " RESET << name << " contents end to begin: ";
	
	it = mutantStack.begin();
	ite--;
	
	for (; ite != it; --ite)
		std::cout << "[" << *ite << "] ";

	std::cout << "[" << *ite << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithReverseIterator(std::string name, MutantStack<T, C> mutantStack)
{
	std::cout << BLUE "Reverse iterator: " RESET << name << " contents rbegin to rend: ";
	
	typename MutantStack<T, C>::reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T, C>::reverse_iterator itre = mutantStack.rend();
	
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";

	std::cout << std::endl << BLUE "Reverse iterator: " RESET << name << " contents rend to rbegin: ";
	
	itr = mutantStack.rbegin();
	itre--;
	
	for (; itre != itr; --itre)
		std::cout << "[" << *itre << "] ";

	std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}

template <typename T, typename C>
void	printMutantStackWithConstReverseIterator(std::string name, MutantStack<T, C> const mutantStack)
{
	std::cout << PURPLE "Const reverse iterator: " RESET << name << " contents rbegin to rend: ";
	
	typename MutantStack<T, C>::const_reverse_iterator itr = mutantStack.rbegin();
	typename MutantStack<T, C>::const_reverse_iterator itre = mutantStack.rend();
	
	for (; itr != itre; ++itr)
		std::cout << "[" << *itr << "] ";

	std::cout << std::endl << PURPLE "Const reverse iterator: " RESET << name << " contents rend to rbegin: ";
	
	itr = mutantStack.rbegin();
	itre--;
	
	for (; itre != itr; --itre)
		std::cout << "[" << *itre << "] ";

	std::cout << "[" << *itre << "] ";
	std::cout << std::endl;
}

void	subjectTest(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----          SUBJECT TESTS          ----" << std::endl
		<< "=========================================" << std::endl;
	
	{
		std::cout << std::endl << "-- Mutant Stack:" << std::endl;
	
		MutantStack<int>	mstack;
	
		mstack.push(5);
		mstack.push(17);

		std::cout << "Stack top (expecting 17): " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Stack size (expecting 1): " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "Iterating over mstack from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
	
		++it;
		--it;
	
		while (it != ite) 
		{
			std::cout << *it << " ";
			++it; 
		}

		std::stack<int>	s(mstack);
		std::cout << std::endl;
	}

	{
		std::cout << std::endl << "-- List:" << std::endl;
		
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "List \"top\" (back) (expecting 17): " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Stack size (expecting 1): " << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::cout << "Iterating over mstack list from begin() to end() (expecting 5, 3, 5, 737, 0): " << std::endl;

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
}

void	intntListMutantStackTest(void)
{
	std::cout << std::endl << "=========================================" << std::endl
		<< "----   MUTANT STACK INT LIST TESTS   ----" << std::endl
		<< "=========================================" << std::endl;

	MutantStack< int, std::list<int> >	mutantStack;

	std::cout << std::endl << GREEN "-- Created empty int mutant stack with list container." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);

	for (int i = 0; i < 10; i++)
		mutantStack.push(i);

	std::cout << std::endl << GREEN "-- Pushed numbers to mutant stack with push()." RESET << std::endl;

	::printMutantStackSize("MS", mutantStack);
	::printMutantStackWithIterator("MS", mutantStack);
	::printMutantStackWithReverseIterator("MS", mutantStack);
	::printMutantStackTop("MS", mutantStack);
}

int	main(void)
{
	::subjectTest();
	::intntListMutantStackTest();

	return (0);
}
