/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:06:11 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/20 19:32:21 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME
/**
 *	Calcule le coût pour ramener le plus petit element au top de la stack
 *	00 = rotate
 *	01 = reverse_rotate 
 **/
int	price_min_top(t_stack *lst)
{
	int		cr;
	int		crr;
	t_stack	*x;

	cr = 0;
	crr = 0;
	x = lst;
	print_stack(x, lst);
	while (x->content != ft_stack_min_value(&x))
	{
		rotate(&x, 0);
		cr++;
	}
	ft_printf("-------------------------------");
	x = lst;
	print_stack(x, lst);
	while (x->content != ft_stack_min_value(&x))
	{
		reverse_rotate(&x, 0);
		crr++;
	}
	if (cr < crr)
		return (0);
	else
		return (1);
}
