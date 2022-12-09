/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:37:43 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/09 19:28:01 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_list **a, int arr[], int len)
{
	int		i;
	t_list	*new;

	i = 0;
	if (!arr)
		return (1);
	while (i < len)
	{
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			ft_lstclear(a, free);
			return (1);
		}
		*(int *)new->content = arr[i];
		ft_printf("%d\t\t%d\t%p\t%p\n", i, *(int *)new->content, new->next, new); //FIXME
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}

int	*arr_str_to_int(char **arr_str, int start)
{
	int	*arr;
	int	len;
	int	i;

	len = start;
	while (arr_str[len])
		len++;
	arr = ft_calloc(len, sizeof(int *));
	if (!arr)
		return (NULL);
	len = start;
	i = 0;
	while (arr_str[len])
		arr[i++] = ft_atoi(arr_str[len++]);
	return (arr);
}

int	arr_len(char **arr, int start)
{
	int	i;

	i = start;
	while (arr[i])
		i++;
	return (i - start);
}
