/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:43 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:51 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **a, int arr[], int len)
{
	int		i;
	t_stack	*new;

	i = 0;
	if (!arr)
		return (1);
	while (i < len)
	{
		new = ft_stack_new(arr[i]);
		if (!new)
		{
			ft_stack_clear(a);
			return (1);
		}
		ft_stack_addback(a, new);
		i++;
	}
	return (0);
}

int	*arr_str_to_int(char **arr_str, int start)
{
	int	*arr;
	int	len;
	int	i;

	len = start;
	while (arr_str[len])
		len++;
	arr = ft_calloc(len, sizeof(int *));
	if (!arr)
		return (NULL);
	len = start;
	i = 0;
	while (arr_str[len])
		arr[i++] = ft_atoi(arr_str[len++]);
	return (arr);
	//return (shift_int(arr, i));
}

int	arr_len(char **arr, int start)
{
	int	i;

	i = start;
	while (arr[i])
		i++;
	return (i - start);
}

// FIXME
int	*shift_int(int arr[], int len)
{
	int	counter;
	int	i;
	int	*cp_arr;
	int	j;

	counter = len - 1;
	i = 0;
	j = 0;
	cp_arr = arr;
	while (i < len)
	{
		while (j < len)
		{
			if (cp_arr[i] < cp_arr[j])
				counter--;
			j++;
		}
		arr[i] = counter++;
		counter = len - 1;
		i++;
	}
	return (arr);
}
