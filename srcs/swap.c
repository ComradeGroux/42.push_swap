/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:17:37 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/07 15:59:34 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**x, char c)
{
	t_list	*tmp;

	tmp = NULL;
	if (ft_lstsize(*x) >= 2)
	{
		tmp = *x;
		*x = (*x)->next;
		tmp->next = (*x)->next;
		(*x)->next = tmp;
		if (c != '\0')
			ft_printf("s%c\n", c);
	}
}

void	ss(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}
