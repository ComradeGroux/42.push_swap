/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2023/02/28 15:34:43 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		print_error_and_exit();
	else if (argc == 2)
		arr_to_list(ft_split(argv[1], ' '), &a, 0);
	else
		arr_to_list(argv, &a, 1);
	if (!is_sort(a))
	{
		if (ft_stack_size(a) <= 3)
			ultra_tiny_sort(&a, &b);
		else if (ft_stack_size(a) <= 5)
			tiny_sort(&a, &b);
		else
			personalsort(&a, &b);
	}
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (EXIT_SUCCESS);
}

void	arr_to_list(char **tmp, t_stack **a, int flag)
{
	if (!tmp)
		print_error_and_exit();
	check_arg(tmp, flag);
	init_stack(a, arr_str_to_int(tmp, flag), arr_len(tmp, flag));
	if (flag == 0)
		ft_free_arr(tmp);
}
