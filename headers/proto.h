/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/08 23:42:17 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	swap(t_list	**x, char c);
void	ss(t_list **a, t_list **b);
void	rotate(t_list **x, char c);
void	rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **x, char c);
void	rrr(t_list **a, t_list **b);
int		check_only_int(char **arg, int index);
int		print_error(char *str);

#endif