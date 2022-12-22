/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:05 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/22 18:13:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Push le top de B sur A
 */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (ft_stack_size(*b) == 1)
	{
		ft_stack_addfront(a, *b);
		*b = NULL;
		ft_printf("pa\n");
	}
	else if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		if (*a == NULL)
		{
			*a = tmp;
			(*a)->next = NULL;
			(*a)->prev = NULL;
		}
		else
			ft_stack_addfront(a, tmp);
		ft_printf("pa\n");
	}
}

/**
 * Push le top de A sur B
 */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (ft_stack_size(*a) == 1)
	{
		ft_stack_addfront(b, *a);
		*a = NULL;
		ft_printf("pb\n");
	}
	else if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		if (*b == NULL)
		{
			*b = tmp;
			(*b)->next = NULL;
			(*b)->prev = NULL;
		}
		else
			ft_stack_addfront(b, tmp);
		ft_printf("pb\n");
	}
}
