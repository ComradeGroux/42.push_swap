/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/22 18:24:02 by vgroux           ###   ########.fr       */
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
	int	mid;

	while (ft_stack_size(*a) > 1)
	{
		mid = ft_stack_mid(*a);
		if ((*a)->content <= mid)
			pb(a, b);
		else
			rotate(a, 'a');
	}
	while (*b)
	{
		if (movecalc(b, ft_stack_min_value(*b) < movecalc(b, ft_stack_max_value(*b))))
		{
			ft_stack_min_top(b, 'b');
			pa(a, b);
			rotate(a, 'a');
		}
		else
		{
			ft_stack_max_top(b, 'b');
			pa(a, b);
		}
	}
	ft_stack_min_top(a, 'a');
}

int	movecalc(t_stack **lst, int tofind)
{
	t_stack *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content == tofind)
			break ;
		tmp = tmp->next;
	}
	print_stack(*lst, NULL);
	ft_printf("%p\t%d\n%p\t%d\n\n", tmp, tmp->content, *lst, (*lst)->content);
	if (ft_stack_find(*lst, tmp->content) > ft_stack_size(*lst) / 2)
		return (ft_stack_size(*lst) - ft_stack_find(*lst, tmp->content) + 1);
	else
		return (ft_stack_find(*lst, tmp->content) - 1);
}
