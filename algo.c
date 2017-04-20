/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 10:59:12 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/16 10:59:32 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

t_env	*ft_rand_map(t_env *d)
{
	int	i;
	int	j;
	int tab[4];

	i = 0;
	srand(time(NULL));
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			tab[0] = rand() % 2;
			tab[1] = rand() % 8;
			tab[2] = rand() % 15;
			tab[3] = rand() % 1000;
			d->tab[i][j] = (tab[d->rand_dens] == 0 ? 1 : 0);
			j++;
		}
		i++;
	}
	return (d);
}

int check_point(int **tab, int i, int j)
{
	int neighbor;
	int a;
	int b;
	int k;
	int l;

	neighbor = 0;
	a = 0;
	k = i - 1;
	l = j - 1;
	while (a < 3)
	{
		b = 0;
		while (b < 3)
		{
			if (((l >= 0) && (k >= 0) && (l < WIDTH) && (k < HEIGHT) && (tab[k][l] == 1)) && ((l != j) || (k != i)))
				neighbor++;		
			b++;
			l++;
		}
		a++;
		k++;
		l -= 3;
	}
	if (neighbor == 2)
		return (tab[i][j]);
	else if (neighbor == 3)
		return (1);
	else 
		return (0);
}

int **check_map(int **tab)
{
	int i;
	int j;
	int **result;

	result = (int **)malloc(sizeof(int *) * HEIGHT - 1);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		result[i] = (int *)malloc(sizeof(int) * WIDTH - 1);
		while (j < WIDTH)
		{
			result[i][j] = check_point(tab, i, j);
			j++;
		}
		i++;
	}

	i = 0;
	while(i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			tab[i][j] = result[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i != WIDTH)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (tab);
}
