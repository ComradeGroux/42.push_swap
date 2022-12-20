/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 13:12:25 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int	check_arg(char **tmp, int flag)
{
	if (!check_only_int(tmp, flag) || !check_duplicate(tmp, flag))
	{
		if (flag == 0)
			ft_free_arr(tmp);
		return (print_error("Error"));
	}
	return (0);
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

int	check_duplicate(char **arg, int i)
{
	int	j;
	int	tmp;
	int	*arr;
	int	len;

	arr = arr_str_to_int(arg, i);
	if (!arr)
		return (0);
	len = arr_len(arg, i);
	i--;
	while (++i < len)
	{
		tmp = arr[i];
		j = i;
		while (arr[++j])
		{
			if (arr[j] == tmp)
			{
				free(arr);
				return (0);
			}
		}
	}
	free(arr);
	return (1);
}
