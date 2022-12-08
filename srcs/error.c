/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/08 14:42:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_isnotdouble(int arr[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_onlydigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]) && !ft_isnegpos(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_arg(int argc, char **argv)
{
	int	i;
	int	*arr;

	i = 0;
	if (argc == 2)
		if (!check_onlydigit(argv[1]))
			return (FALSE);
	else
	{
		while (++i < argc)
		{
			if (!check_onlydigit(argv[i]))
				return (FALSE);
		}
	}
	return (FALSE);
}
