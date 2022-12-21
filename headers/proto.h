/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/21 14:16:27 by vgroux           ###   ########.fr       */
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
void	arr_to_list(char **tmp, t_stack **a, int flag);

t_stack	*ft_stack_new(int content);
void	ft_stack_addback(t_stack **lst, t_stack *new);
void	ft_stack_addfront(t_stack **lst, t_stack *new);
t_stack	*ft_stack_last(t_stack *lst);
int		ft_stack_size(t_stack *lst);
void	ft_stack_clear(t_stack **lst);
int		is_sort(t_stack *a);
int		ft_stack_max_value(t_stack *lst);
int		ft_stack_min_value(t_stack *lst);
int		ft_stack_find(t_stack *lst, int x);
void	ft_stack_min_top(t_stack **lst, char c);
void	ft_stack_max_top(t_stack **lst, char c);
int		ft_stack_mid(t_stack *lst);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack	**x, char c);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **x, char c);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **x, char c);
void	rrr(t_stack **a, t_stack **b);

void	print_error_and_exit(void);
void	check_arg(char **tmp, int flag);
void	check_only_int(char **arg, int index);
void	check_duplicate(char **tmp, int index);

void	init_stack(t_stack **a, int arr[], int flag);
int		*arr_str_to_int(char **arr_str, int start);
int		arr_len(char **arr, int start);
int		*shift_int(int arr[], int len);

void	sort(t_stack **a, t_stack **b);
void	ultra_tiny_sort(t_stack **a, t_stack **b);
void	tiny_sort(t_stack **a, t_stack **b);
void	quicksort(t_stack **a, t_stack **b);

void	print_stack(t_stack *a, t_stack *b);
void	quicktest(t_stack **a, t_stack **b);

#endif