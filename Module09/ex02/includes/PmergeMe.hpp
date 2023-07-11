/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:37:36 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 13:03:31 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &origin);
		PmergeMe	&operator=(const PmergeMe &origin);
		~PmergeMe();

		void	ft_sort(char **tab);
		void	printVector();
		void	printDeque();

		template< typename T >
		void	merge_sort(T &lst, int beg, int end)
		{
			int	mid;

			if (beg < end)  
			{
				mid = (beg + end) / 2;

				merge_sort(lst, beg, mid);
				merge_sort(lst, mid + 1, end);
				merge(lst, beg, mid, end);
			}
		}

		template< typename T >
		void	merge(T &lst, int left, int mid, int right)
		{
			std::vector<int>	temp(right - left + 1);
			int					i = left;
			int					j = mid + 1;
			int					k = 0;

			while (i <= mid && j <= right)
			{
				if (lst[i] <= lst[j])
					temp[k++] = lst[i++];
				else
					temp[k++] = lst[j++];
			}

			while (i <= mid)
				temp[k++] = lst[i++];

			while (j <= right)
				temp[k++] = lst[j++];

			for (int p = 0; p < k; p++)
				lst[left + p] = temp[p];
		}
};

#endif