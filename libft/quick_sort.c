/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:06:35 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 15:22:29 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_arr(int *set, int a, int b)
{
	int	temp;

	temp = set[a];
	set[a] = set[b];
	set[b] = temp;
}

//quick sort ft
//this ft is recursive ft.
//first call form is quick_sort(set, 0, last_index);
void	quick_sort(int	*set, int min, int sup)
{
	int	m;
	int	s;
	int	pivot;

	m = min;
	s = sup;
	pivot = set[(min + sup) / 2];
	while (m <= s)
	{
		while (set[m] < pivot)
			m++;
		while (set[s] > pivot)
			s--;
		if (m <= s)
		{
			if (m != s)
				swap_arr(set, m, s);
			m++;
			s--;
		}
	}
	if (min < s)
		quick_sort(set, min, s);
	if (m < sup)
		quick_sort(set, m, sup);
}
