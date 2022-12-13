/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:43 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/13 19:09:00 by vgroux           ###   ########.fr       */
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
	*a = (*a)->next;
	free((*a)->prev);
	(*a)->prev = NULL;
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
}

int	arr_len(char **arr, int start)
{
	int	i;

	i = start;
	while (arr[i])
		i++;
	return (i - start);
}
