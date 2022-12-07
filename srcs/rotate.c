/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/07 15:59:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **x, char c)
{
	ft_lstadd_back(x, (*x)->next);
	*x = (*x)->next;
	if (c != '\0')
		ft_printf("r%c\n", c);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **x, char c)
{
	t_list	*tmp;

	tmp = *x;
	ft_lstadd_front(x, ft_lstlast(*x));
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	if (c != '\0')
		ft_printf("rr%c\n", c);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
