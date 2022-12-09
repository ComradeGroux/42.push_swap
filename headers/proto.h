/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/09 18:11:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int		main(int argc, char **argv);
int		arr_to_list(char **tmp, t_list **a, int flag);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	swap(t_list	**x, char c);
void	ss(t_list **a, t_list **b);
void	rotate(t_list **x, char c);
void	rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **x, char c);
void	rrr(t_list **a, t_list **b);

int		print_error(char *str);
int		check_arg(char **tmp, int flag);
int		check_only_int(char **arg, int index);
int		check_duplicate(char **tmp, int index);

int		init_stack(t_list **a, int arr[], int flag);
int		*arr_str_to_int(char **arr_str, int start);
int		arr_len(char **arr, int start);

#endif