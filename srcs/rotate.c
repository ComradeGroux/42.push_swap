/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/24 00:41:41 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Premier element devient le dernier
 */
void	rotate(t_stack **x, char c)
{
	if (ft_stack_size(*x) != 1)
	{
		*x = (*x)->next;
		ft_stack_addback(x, (*x)->prev);
		(*x)->prev = NULL;
		if (c != '\0')
			ft_printf("r%c\n", c);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

/**
 * Dernier element devient le premier
 */
void	reverse_rotate(t_stack **x, char c)
{
	t_stack	*new;
	t_stack	*tmp;

	if (ft_stack_size(*x) != 1)
	{
		new = ft_stack_last(*x);
		tmp = *x;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		ft_stack_addfront(x, new);
		if (c != '\0')
			ft_printf("rr%c\n", c);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
