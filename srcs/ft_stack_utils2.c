/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:17:19 by vgroux            #+#    #+#             */
/*   Updated: 2023/01/20 17:34:44 by vgroux           ###   ########.fr       */
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
 * Retourne la mediane de la stack
 */
int	ft_stack_mid(t_stack *lst, int max, int min)
{
	t_stack	*tmp;
	int		*arr;
	int		i;
	int		j;
	int		len;
	int		temp;

	tmp = lst;
	arr = ft_calloc(max - min + 1, sizeof(int));
	if (!arr)
		return (ft_stack_moy(lst));
	len = 0;
	while (tmp)
	{
		if (tmp->content >= min && tmp->content <= max)
			arr[len++] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			j++;
		}
		i++;
	}
	temp = arr[len / 2];
	// ft_printf("min: %d\tmax: %d\tmedian: %d\n", min, max, temp);
	free(arr);
	return (temp);
}
