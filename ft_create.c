/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:35:19 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/16 11:35:40 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

t_env	*ft_create(t_env *d, GLFWwindow *window)
{
	int	i;
	int	j;
	int	k;

	i = 11;
	j = 11;
	k = 0;
	while (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (d->tab[i][j] == 0)
		{
			k = 0;
			d->tab[i][j] = 1;
		}
		else if (d->tab[j][i] == 1)
		{
			k = 1;
			d->tab[i][j] = 1;
		}
		if(glfwGetKey(window, 'A'))
		{
			if (k == 0)
			{
				d->tab[i][j] = 1;
				k = 1;
			}
			else
				k = 0;
		}
		d = ft_map(d);
		if (glfwGetKey(window, GLFW_KEY_LEFT) && j != WIDTH - 10)
		{
			if (k == 0)
				d->tab[i][j] = 0;
			j++;
		}
		else if (glfwGetKey(window, GLFW_KEY_RIGHT) && j != 10)
		{
			if (k == 0)
				d->tab[i][j] = 0;
			j--;
		}
		else if (glfwGetKey(window, GLFW_KEY_UP) && i != 10)
		{
			if (k == 0)
				d->tab[i][j] = 0;
			i--;
		}
		else if (glfwGetKey(window, GLFW_KEY_DOWN) && i != HEIGHT - 10)
		{
			if (k == 0)
				d->tab[i][j] = 0;
			i++;
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (d);
}

t_env	*ft_rand(t_env *d, GLFWwindow *window)
{
	d->rand_dens = 4;
	while (d->rand_dens == 4)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (glfwGetKey(window, 'V'))
			d->rand_dens = 0;
		else if (glfwGetKey(window, 'B'))
			d->rand_dens = 1;
		else if (glfwGetKey(window, 'N'))
			d->rand_dens = 2;
		else if (glfwGetKey(window, 'M'))
			d->rand_dens = 3;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	d = ft_rand_map(d);
	return (d);
}
