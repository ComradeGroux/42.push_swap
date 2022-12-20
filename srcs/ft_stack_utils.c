/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:24 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 18:41:47 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	clear_stack(t_stack **a, t_stack **b)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
}

int	is_sort(t_stack *a)
{
	int	tmp;

	tmp = a->content;
	while (a)
	{
		if (tmp > a->content)
			return (0);
		tmp = a->content;
		a = a->next;
	}
	return (1);
}

int	ft_stack_max_value(t_stack **lst)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_stack_min_value(t_stack **lst)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
