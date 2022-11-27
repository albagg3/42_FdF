/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:08:01 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/27 16:27:56 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stdio.h>

void zoom (t_point *points, int len, float scale)
{
	int i;

	i = 0;
	while (i < len)
	{
		points[i].coordinates[X] *= scale;
		points[i].coordinates[Y] *= scale;
		points[i].coordinates[Z] *= scale;
		i++;
	}


}

void ft_reduce_z(int len, t_point *points, float divisor)
{
	int i;

	i = 0;
	while (i < len)
	{
		points[i].coordinates[Z] /= divisor;
		i++;
	}
}

 
void angle(float *angle, float value)
{
	*angle += value;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >= 360)
		*angle = *angle - 360;
}
