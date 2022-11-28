/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:08:01 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/28 14:33:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stdio.h>

void	zoom(t_point *points, int len, float scale)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].coord[X] *= scale;
		points[i].coord[Y] *= scale;
		points[i].coord[Z] *= scale;
		i++;
	}
}

void	ft_reduce_z(int len, t_point *points, float divisor)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].coord[Z] /= divisor;
		i++;
	}
}

void	traslate_to_a_point(int len, t_point *points, t_point distance)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].coord[X] += distance.coord[X];
		points[i].coord[Y] += distance.coord[Y];
		points[i].coord[Z] += distance.coord[Z];
		i++;
	}
}

void	angle(float *angle, float value)
{
	*angle += value;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >= 360)
		*angle = *angle - 360;
}
