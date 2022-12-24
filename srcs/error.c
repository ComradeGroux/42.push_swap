/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/24 13:39:12 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	check_arg(char **tmp, int flag)
{
	check_only_int(tmp, flag);
	check_duplicate(tmp, flag);
}

void	check_only_int(char **arg, int index)
{
	int	i;

	i = 0;
	if (!arg)
		print_error_and_exit();
	while (arg[index])
	{
		if (ft_isnegpos(arg[index][0]))
			i = 1;
		else
			i = 0;
		if (arg[index][i] == '\0')
			print_error_and_exit();
		while (arg[index][i])
		{
			if (!ft_isdigit(arg[index][i]))
				print_error_and_exit();
			i++;
		}
		if (ft_atol(arg[index]) > INT_MAX || ft_atol(arg[index]) < INT_MIN)
			print_error_and_exit();
		index++;
	}
}

void	check_duplicate(char **arg, int i)
{
	int	j;
	int	tmp;
	int	*arr;
	int	len;

	arr = arr_str_to_int(arg, i);
	if (!arr)
		print_error_and_exit();
	len = arr_len(arg, i);
	i = 0;
	while (i < len)
	{
		tmp = arr[i];
		j = i;
		while (++j < len)
		{
			if (arr[j] == tmp)
			{
				free(arr);
				print_error_and_exit();
			}
		}
		i++;
	}
	free(arr);
}
