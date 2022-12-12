/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/12 20:55:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
int		arr_to_list(char **tmp, t_stack **a, int flag);

t_stack	*ft_stack_new(int content);
void	ft_stack_addback(t_stack **lst, t_stack *new);
void	ft_stack_addfront(t_stack **lst, t_stack *new);
t_stack	*ft_stack_last(t_stack *lst);
int		ft_stack_size(t_stack *lst);
void	ft_stack_clear(t_stack **lst);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack	**x, char c);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **x, char c);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **x, char c);
void	rrr(t_stack **a, t_stack **b);

int		print_error(char *str);
int		check_arg(char **tmp, int flag);
int		check_only_int(char **arg, int index);
int		check_duplicate(char **tmp, int index);

int		init_stack(t_stack **a, int arr[], int flag);
int		*arr_str_to_int(char **arr_str, int start);
int		arr_len(char **arr, int start);

#endif