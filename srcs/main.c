/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/08 23:13:49 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tmp;

	if (argc == 1)
		ft_putendl_fd("Error", 2);
	else if (argc == 2)
	{
		tmp = ft_split(argv, ' ');
		if (!tmp)
			ft_putendl_fd("Error", 2);
		else
		{
			if (!check_only_int(tmp, 0))
				ft_putendl_fd("Error", 2);
			ft_free_arr(tmp);
		}
	}
	else
	{
		if (!check_only_int(argv, 1))
			ft_putendl_fd("Error", 2);
	}
	return (0);
}
