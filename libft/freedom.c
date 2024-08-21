/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:10 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 14:10:31 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//this ft free and dangling int arr.
//using form is int_dangling(&int_arr);
//if int_arr = 0, do nothinig 
int	int_dangling(int **ptr)
{
	if (!*ptr)
		return (0);
	free(*ptr);
	*ptr = 0;
	return (0);
}

//this ft free and dangling char arr.
//using form is char_dangling(&char_arr);
//if char_arr is 0, do nothing
int	char_dangling(char **str)
{
	if (!*str)
		return (0);
	free(*str);
	*str = 0;
	return (0);
}

//this ft free and dangling double char arr.
//using form is free_double(&double_char_arr);
//if double_char_arr is 0, do nothing
int	free_double(char ***str)
{
	char	**temp;

	if (!str)
		return (0);
	temp = *str;
	while (*temp)
	{
		char_dangling(&(*temp));
		temp++;
	}
	free(*str);
	*str = 0;
	return (0);
}
