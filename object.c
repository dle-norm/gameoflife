/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 16:33:06 by dle-norm          #+#    #+#             */
/*   Updated: 2015/09/15 16:33:09 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

float	*balle(float x, float y, float *ball)
{
	ball[0] = x;
	ball[1] = y;
	ball[2] = x + 0.01;
	ball[3] = y;
	ball[4] = x;
	ball[5] = y + 0.01;
	ball[6] = x + 0.01;
	ball[7] = y + 0.01;
	ball[8] = x + 0.01;
	ball[9] = y;
	ball[10] = x;
	ball[11] = y + 0.01;
	return (ball);
}

void	draw(float x, float y)
{
	float	*ball;

	ball = (float *)malloc(sizeof(float) * 11);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, balle(x, y, ball));
	glEnableVertexAttribArray(0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	free(ball);
}