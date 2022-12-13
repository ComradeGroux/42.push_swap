/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:17:37 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/13 18:30:38 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **x, char c)
{
	t_stack	*tmp;

	tmp = NULL;
	if (ft_stack_size(*x) >= 2)
	{
		tmp = *x;
		*x = (*x)->next;
		tmp->next = (*x)->next;
		tmp->prev = *x;
		tmp->next->prev = tmp;
		(*x)->next = tmp;
		(*x)->prev = NULL;
		if (c != '\0')
			ft_printf("s%c\n", c);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}
