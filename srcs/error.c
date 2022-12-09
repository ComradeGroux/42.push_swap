/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/09 12:34:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int	check_only_int(char **arg, int index)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[index])
	{
		if (ft_isnegpos(arg[index][0]))
			i = 1;
		else
			i = 0;
		while (arg[index][i])
		{
			if (!ft_isdigit(arg[index][i]))
				return (0);
			i++;
		}
		if (ft_atol(arg[index]) > INT_MAX || ft_atol(arg[index]) < INT_MIN)
			return (0);
		index++;
	}
	return (1);
}

int	check_duplicate(char **arg, int index)
{
	int	i;
	int	j;
	int	tmp;
	int	*arr;
	int	len;

	i = index;
	while (arg[i])
		i++;
	arr = ft_calloc(i, sizeof(int *));
	if (!arr)
		return (0);
	len = index;
	while (arg[len])
	{
		arr[len] = ft_atoi(arg[len]);
		len++;
	}
	len -= index;
	i = index;
	while (i < len)
	{
		tmp = arr[i];
		j = i + 1;
		while (arr[j])
		{
			if (arr[j] == tmp)
			{
				free(arr);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(arr);
	return (1);
}
