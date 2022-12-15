/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:32:35 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/15 18:15:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (*b == NULL && is_sort(*a))
		return ;
	else if (*b == NULL && ft_stack_size(*a) <= 5)
		tiny_sort(a, b);
	else
		quicksort(a, b);
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
