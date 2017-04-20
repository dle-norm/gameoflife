/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:46:26 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/15 16:46:27 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"
#include <stdio.h>

t_env	*ft_grill(t_env *d)
{
	int	i;
	int	j;

	i = 0;
	d->tab = (int**)malloc(sizeof(int*) * HEIGHT - 1);
	while (i <= HEIGHT)
	{
		d->tab[i] = (int*)malloc(sizeof(int) * WIDTH - 1);
		i++;
	}
	return (d);
}

t_env	*ft_map(t_env *d)
{
	int	i;
	int	j;

	i = 0;
	d->y = 0.99;
	while (i != HEIGHT)
	{
		j = 0;
		d->x = 0.99;
		while (j != WIDTH)
		{
			if (d->tab[i][j] == 1)
			{
				draw(d->x, d->y);
			}
			j++;
			d->x -= 0.01;
		}
		i++;
		d->y -= 0.01;
	}
	return (d);
}
