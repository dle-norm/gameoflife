/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:21:56 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/15 16:21:57 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void	ft_graph(void)
{
	GLFWwindow	*window;
	t_env		*d;
	int			i;
	int 		j;

	i = 0;
	d = (t_env*)malloc(sizeof(t_env));
	d = ft_grill(d);
	if (!glfwInit())
		ft_error("Initialisation OpenGL echoue\n");
	window = glfwCreateWindow(640, 480, "life", NULL, NULL);
	if (window == NULL)
		ft_error("Impossible d'ouvrir la fenetre\n");
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	if (!window)
	{
		glfwTerminate();
		ft_error("Initialisation OpenGL echoue\n");
	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& glfwWindowShouldClose(window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if(glfwGetKey(window, 'E'))
		{
			if (i == 0)
				i = 2;
			else
				i = 0;
		}
		if (i == 2)
			d = ft_rand(d, window);
		if(glfwGetKey(window, 'D'))
			d = ft_grill(d);
		if (glfwGetKey(window, GLFW_KEY_SPACE))
		{
			if (i == 0)
				i = 1;
			else
				i = 0;
		}
		if (i == 1)
			d = ft_create(d, window);
		d = ft_map(d);
		d->tab = check_map(d->tab);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	i = 0;
	while (i < WIDTH)
	{
		free(d->tab[i]);
		i++;
	}
	free(d->tab);
	free(d);
	glfwTerminate();
}
