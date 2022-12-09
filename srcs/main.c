/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/09 12:35:27 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	
	a = NULL;
	(void)b;
	if (argc == 1)
		return (print_error("Error"));
	else if (argc == 2)
	{
		if (arr_to_list(ft_split(argv[1], ' '), a, 0))
			return (1);
		// TODO ALGO like "ft_algo(a, b)"
	}
	else
	{
		if (arr_to_list(argv, a, 1))
			return (1);
		if (!check_only_int(argv, 1))
			return (print_error("Error"));
		// TODO ALGO like "ft_algo(a, b)"
	}
	return (0);
}

int	arr_to_list(char **tmp, t_list **a, int flag)
{
	(void)a;
	if (!tmp)
		return (print_error("Error"));
	else
	{
		if (!check_only_int(tmp, flag))
		{
			if (flag == 0)
				ft_free_arr(tmp);
			return (print_error("Error"));
		}
		else
		{
			if (!check_duplicate(tmp, flag))
			{
				if (flag == 0)
					ft_free_arr(tmp);
				return (print_error("Error"));
			}
		}
		if (flag == 0)
			ft_free_arr(tmp);
	}
	return (0);
}
