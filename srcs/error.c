/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/07 17:40:17 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_isexist(void)
{
	return (FALSE);
}

t_bool	check_onlydigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]) && !ft_isnegpos(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_arg(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (FALSE);
}
