/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/08 23:45:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc == 1)
		return (print_error("Error"));
	else if (argc == 2)
		if (str_to_list(ft_split(argv[1], ' '), a))
			return (1);
	else
	{
		if (!check_only_int(argv, 1))
			return (print_error("Error"));
	}
	return (0);
}

int	str_to_list(char **tmp, t_list **a)
{
	if (!tmp)
		return (print_error("Error"));
	else
	{
		if (!check_only_int(tmp, 0))
			return (print_error("Error"));
		else
		{
			if (!check_duplicate(tmp))
				return (print_error("Error"));
		}
		ft_free_arr(tmp);
	}
	return (0);
}
