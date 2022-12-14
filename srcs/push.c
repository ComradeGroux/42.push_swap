/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:05 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/14 16:52:54 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b) //FIXME
{
	t_stack	*tmp;

	tmp = NULL;
	if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b) //FIXME
{
	t_stack	*tmp;

	tmp = NULL;
	if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
		ft_printf("pb\n");
	}
}
