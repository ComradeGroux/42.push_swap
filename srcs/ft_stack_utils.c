/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:24 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/13 20:07:01 by vgroux           ###   ########.fr       */
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

int	is_sort(t_stack *a)
{
	int	tmp;

	tmp = a->content;
	while (a->next != NULL)
	{
		if (tmp > a->content)
			return (0);
		tmp = a->content;
		a = a->next;
	}
	if (tmp > a->content)
		return (0);
	return (1);
}
