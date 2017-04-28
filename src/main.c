/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:11:50 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/15 16:12:34 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void	ft_help(void)
{
	ft_putstr("la tu met un gros man qui pue");
	exit(0);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}

int		main(int ac, char **av)
{
	t_env *env;

	env = NULL;
	if (ft_strcmp(av[1], "-help") == 0)
		ft_help();
	if (ac > 1)
		ft_error("pas d'argument\n");
	ft_graph();
	return (0);
}
