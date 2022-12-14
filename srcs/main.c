/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/24 14:02:32 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("t_stack\tA:\n");
	if (a != NULL)
	{
		while (a->next != NULL)
		{
			ft_printf("current: %p\t\tdata: %d\t\tprev: %p\t\tnext: %p\n", \
			a, a->content, a->prev, a->next);
			a = a->next;
		}
		ft_printf("current: %p\t\tdata: %d\t\tprev: %p\t\tnext: %p\n\n", \
		a, a->content, a->prev, a->next);
	}
	else
		ft_printf("%p\n\n", a);
	ft_printf("t_stack\tB:\n");
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			ft_printf("current: %p\t\tdata: %d\t\tprev: %p\t\tnext: %p\n", \
			b, b->content, b->prev, b->next);
			b = b->next;
		}
		ft_printf("current: %p\t\tdata: %d\t\tprev: %p\t\tnext: %p\n\n", \
		b, b->content, b->prev, b->next);
	}
	else
		ft_printf("%p\n\n", b);
}

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
	sort(&a, &b);
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
