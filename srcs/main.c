/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/13 18:52:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (print_error("Error"));
	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		return (1);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
	{
		free(a);
		return (1);
	}
	else if (argc == 2)
	{
		if (arr_to_list(ft_split(argv[1], ' '), &a, 0))
			return (1);
	}
	else
	{
		if (arr_to_list(argv, &a, 1))
			return (1);
	}
	t_stack	*tmp;
	tmp = a;
	while (tmp)
	{
		ft_printf("%d\t", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
	// TODO ALGO like "ft_algo(a, b)"
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

int	arr_to_list(char **tmp, t_stack **a, int flag)
{
	if (!tmp)
		return (print_error("Error"));
	else if (!check_arg(tmp, flag))
	{
		if (init_stack(a, arr_str_to_int(tmp, flag), arr_len(tmp, flag)))
		{
			if (flag == 0)
				ft_free_arr(tmp);
			return (1);
		}
		else if (flag == 0)
			ft_free_arr(tmp);
	}
	return (0);
}
