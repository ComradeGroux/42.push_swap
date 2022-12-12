/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:59:31 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/12 21:28:25 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_stack_addback(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL && new != NULL)
	{
		*lst = new;
	}
	else if (new && lst)
	{
		while (temp->next != NULL) // FIXME #heap-buffer-overflow
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}

void	ft_stack_addfront(t_stack **lst, t_stack *new)
{
	if (new && lst)
	{
		new->next = *lst;
		new->prev = NULL;
		*lst = new;
		new->next->prev = new;
	}
}

t_stack	*ft_stack_last(t_stack *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

int	ft_stack_size(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
