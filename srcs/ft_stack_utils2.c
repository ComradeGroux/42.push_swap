/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:17:19 by vgroux            #+#    #+#             */
/*   Updated: 2023/01/19 20:00:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Met l'element le plus petit en haut de la stack
 */
void	ft_stack_min_top(t_stack **lst, char c)
{
	int	min;

	min = ft_stack_min_value(*lst);
	if (ft_stack_find(*lst, min) < ft_stack_size(*lst) / 2)
	{
		while ((*lst)->content != min)
			rotate(lst, c);
	}
	else
	{
		while ((*lst)->content != min)
			reverse_rotate(lst, c);
	}
}

/**
 * Met l'element le plus grand en haut de la stack
 */
void	ft_stack_max_top(t_stack **lst, char c)
{
	int	max;

	max = ft_stack_max_value(*lst);
	if (ft_stack_find(*lst, max) < ft_stack_size(*lst) / 2)
	{
		while ((*lst)->content != max)
			rotate(lst, c);
	}
	else
	{
		while ((*lst)->content != max)
			reverse_rotate(lst, c);
	}
}

/**
 * Retourne la moyenne de la stack
 */
int	ft_stack_moy(t_stack *lst)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		count += tmp->content;
		tmp = tmp->next;
	}
	return (count / ft_stack_size(lst));
}

/**
 * Retourne la medianne de la stack
 */
int	ft_stack_mid(t_stack *lst)
{
	int	size;
	int	max;
	int	min;

	size = ft_stack_size(lst);
	max = ft_stack_max_value(lst);
	min = ft_stack_min_value(lst);
	return (ft_stack_moy(lst));
}
