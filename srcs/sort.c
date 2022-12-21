/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/21 17:28:08 by vgroux           ###   ########.fr       */
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
		// quicktest(a, b);
}

void	ultra_tiny_sort(t_stack **a, t_stack **b)
{
	(void)b;
	if ((*a)->content == ft_stack_min_value(*a))
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->content != ft_stack_max_value(*a))
	{
		if ((*a)->next->content == ft_stack_max_value(*a))
			reverse_rotate(a, 'a');
		else
			swap(a, 'a');
	}
	else
	{
		if ((*a)->next->content == ft_stack_min_value(*a))
			rotate(a, 'a');
		else
		{
			swap(a, 'a');
			reverse_rotate(a, 'a');
		}
	}
}

void	tiny_sort(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 5)
	{
		ft_stack_min_top(a, 'a');
		pb(a, b);
		ft_stack_min_top(a, 'a');
		pb(a, b);
		ultra_tiny_sort(a, b);
		pa(a, b);
		pa(a, b);
	}
	else
	{
		ft_stack_min_top(a, 'a');
		pb(a, b);
		ultra_tiny_sort(a, b);
		pa(a, b);
	}
}

//TODO
void	quicksort(t_stack **a, t_stack **b)
{
	int	ilen;

	while (ft_stack_size(*a) > 5)
	{
		ilen = ft_stack_size(*a);
		while (ft_stack_size(*a) > ilen / 2)
		{
			ft_stack_min_top(a, 'a');
			pb(a, b);
		}
	}
	tiny_sort(a, b);
	while (*b)
	{
		ft_stack_max_top(b, 'b');
		pa(a, b);
	}
}

// TODO TEST
void	quicktest(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_stack_min_top(a, 'a');
		pb(a, b);
	}
	ultra_tiny_sort(a, b);
	while (*b)
		pa(a, b);
}
