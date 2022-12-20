/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:43 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 18:07:04 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, int arr[], int len)
{
	int		i;
	t_stack	*new;

	i = 0;
	if (!arr)
		print_error_and_exit();
	while (i < len)
	{
		new = ft_stack_new(arr[i]);
		if (!new)
		{
			ft_stack_clear(a);
			print_error_and_exit();
		}
		ft_stack_addback(a, new);
		i++;
	}
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
	return (shift_int(arr, i));
}

int	arr_len(char **arr, int start)
{
	int	i;

	i = start;
	while (arr[i])
		i++;
	return (i - start);
}

int	*shift_int(int arr[], int len)
{
	int	i;
	int	j;
	int	*cp_arr;
	int	counter;

	i = 0;
	cp_arr = ft_calloc(len, sizeof(int));
	while (i < len)
	{
		j = 0;
		counter = 0;
		while (j < len)
		{
			if (arr[i] > arr[j])
				counter++;
			j++;
		}
		cp_arr[i] = counter;
		i++;
	}
	free(arr);
	return (cp_arr);
}
