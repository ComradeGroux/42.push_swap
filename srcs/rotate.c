/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/12 17:14:45 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **x, char c)
{
	ft_stack_addback(x, (*x)->next);
	*x = (*x)->next;
	(*x)->prev = NULL;
	if (c != '\0')
		ft_printf("r%c\n", c);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack **x, char c)
{
	t_stack	*tmp;

	tmp = *x;
	ft_stack_addfront(x, ft_stack_last(*x));
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	if (c != '\0')
		ft_printf("rr%c\n", c);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
