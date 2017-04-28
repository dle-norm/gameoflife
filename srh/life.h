/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:12:42 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/15 16:13:10 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include "libft/libft.h"
# include "./glfw/include/GLFW/glfw3.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# define HEIGHT 400
# define WIDTH 400

typedef struct	s_env
{
	int		**tab;
	float	x;
	float	y;
	int 	rand_dens;
}				t_env;

t_env	*ft_rand(t_env *d, GLFWwindow *window);
t_env	*ft_create(t_env *d, GLFWwindow *window);
t_env	*ft_grill(t_env *d);
int **check_map(int **tab);
t_env	*ft_grill(t_env *d);
t_env	*ft_map(t_env *d);
void	draw(float x, float y);
float	*balle(float x, float y, float *ball);
void	ft_graph(void);
void	ft_help(void);
void	ft_error(char *s);
int		main(int ac, char **av);
t_env	*ft_rand_map(t_env *d);

#endif
