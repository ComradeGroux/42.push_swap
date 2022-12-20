/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 17:11:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (*b == NULL && is_sort(*a))
		return ;
	else if (*b == NULL && ft_stack_size(*a) <= 3)
		ultra_tiny_sort(a, b);
	else if (*b == NULL && ft_stack_size(*a) <= 5)
		tiny_sort(a, b);
	else
		quicksort(a, b);
}

void	ultra_tiny_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if ((*a)->content == 0)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->content == 1)
	{
		if ((*a)->next->content == 2)
			reverse_rotate(a, 'a');
		else
			swap(a, 'a');
	}
	else
	{
		if ((*a)->next->content == 0)
			rotate(a, 'a');
		else
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
	}
}

// TODO
void	tiny_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

//TODO
void	quicksort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}
